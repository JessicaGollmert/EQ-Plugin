/*
  ==============================================================================

    Audio.cpp
    Author:  Tom Mitchell

  ==============================================================================
*/

#include "Audio.h"
#include <atomic>

Audio::Audio()
{
    audioSourcePlayer.setSource (&filePlayer);
    
    auto midiInputDevices = MidiInput::getAvailableDevices();
    if (midiInputDevices.size() > 0)
        audioDeviceManager.setMidiInputDeviceEnabled (midiInputDevices[0].identifier, true);
    audioDeviceManager.addMidiInputCallback ("", this);
    
    auto errorMessage = audioDeviceManager.initialiseWithDefaultDevices (1, 2);
    if ( ! errorMessage.isEmpty())
        DBG (errorMessage);
    audioDeviceManager.addAudioCallback (this);
}

Audio::~Audio()
{
    audioDeviceManager.removeAudioCallback (this);
    audioDeviceManager.removeMidiInputCallback ("", this);
    
    //remove the file player from the source
    audioSourcePlayer.setSource (nullptr);
}

FilePlayback* Audio::getFilePlayer()
{
    return &filePlayer;
}

void Audio::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{ 
    if (message.isNoteOnOrOff())
    {
        if (message.getVelocity() == 0)
        {
            DBG ("Note Off");
        }
        else
        {
            DBG ("Note On : Channel " << message.getChannel() << " , Note Number " << message.getNoteNumber() << " , Note in Hertz " << message.getMidiNoteInHertz(message.getNoteNumber()) << "Hz , Velocity " << message.getVelocity());
        }
    }
}

void Audio::audioDeviceIOCallback (const float** inputChannelData,
                                           int numInputChannels,
                                           float** outputChannelData,
                                           int numOutputChannels,
                                           int numSamples)
{
    // get the audio from our file player - player puts samples in the output buffer
    audioSourcePlayer.audioDeviceIOCallback (inputChannelData, numInputChannels, outputChannelData, numOutputChannels, numSamples);
    
    //All audio processing is done here
    const float* inL = inputChannelData[0];

    float *outL = outputChannelData[0];
    float *outR = outputChannelData[1];
    
    while(numSamples--)
    {
        float fileOutL = *outL;
        float fileOutR = *outR;
        
        *outL = fileOutL;
        *outR = fileOutR;
        
        inL++;
        outL++;
        outR++;
    }
}

void Audio::audioDeviceAboutToStart (AudioIODevice* device)
{
    audioSourcePlayer.audioDeviceAboutToStart (device);
}

void Audio::audioDeviceStopped()
{
    audioSourcePlayer.audioDeviceStopped();
}
