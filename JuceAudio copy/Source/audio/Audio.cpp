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
//    audioSourcePlayer.setSource (&filePlayer);
    
    auto midiInputDevices = MidiInput::getAvailableDevices();
    if (midiInputDevices.size() > 0)
        audioDeviceManager.setMidiInputDeviceEnabled (midiInputDevices[0].identifier, true);
    audioDeviceManager.addMidiInputCallback ("", this);
    
    auto errorMessage = audioDeviceManager.initialiseWithDefaultDevices (1, 2);
    if ( ! errorMessage.isEmpty())
        DBG (errorMessage);
    audioDeviceManager.addAudioCallback (this);
    
//    hpf.setCoefficients ( IIRCoefficients::makeLowPass (samplerate, 100.0f, 0.5f ) );
    
//    bpf.setFilter(samplerate, 1000.0f, 0.1f);
//    lpf.setFilter(samplerate, 20000.0f, 0.1f);
//    hpf.setFilter(samplerate, 100.0f, 0.5f);
}

Audio::~Audio()
{
    audioDeviceManager.removeAudioCallback (this);
    audioDeviceManager.removeMidiInputCallback ("", this);
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
//    audioSourcePlayer.audioDeviceIOCallback (inputChannelData, numInputChannels, outputChannelData, numOutputChannels, numSamples);
    
    //All audio processing is done here
    const float* inL = inputChannelData[0];

    float *outL = outputChannelData[0];
    float *outR = outputChannelData[1];
    
    while(numSamples--)
    {
        
//        bpf.applyFilter(outL, numSamples);

//        lpf.applyFilter(outL, numSamples);

//        hpf.applyFilter(outL, numSamples);
//        hpf.applyFilter(filePlayer.audioBuffer.getWritePointer(0), filePlayer.audioBuffer.getNumSamples()); // crashes
        
        
        *outL = filePlayer.processSampleL(*outL); // mono -> needs to be stereo
        *outR = *outL;
        
        inL++;
        outL++;
        outR++;
    }
}

void Audio::audioDeviceAboutToStart (AudioIODevice* device)
{
    samplerate = device->getCurrentSampleRate();
    filePlayer.setSamplerate(device->getCurrentSampleRate());
}

void Audio::audioDeviceStopped()
{

}

void Audio::updateFilters(float frequency, float q)
{
    hpf.setCoefficients ( IIRCoefficients::makeLowPass (samplerate, frequency, q ) );
    std::cout << frequency << "\n" << q << "\n";
}