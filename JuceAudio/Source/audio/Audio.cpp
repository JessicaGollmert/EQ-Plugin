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
    oscPtr = &oscillatorSin;
    
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
}


void Audio::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{ 
    if (message.isNoteOnOrOff())
    {
//        if (message.getVelocity() == 0)
//        {
//            DBG ("Note Off")
//        }
        DBG ("Note On : Channel " << message.getChannel() << " , Note Number " << message.getNoteNumber() << " , Note in Hertz " << message.getMidiNoteInHertz(message.getNoteNumber()) << "Hz , Velocity " << message.getVelocity());

        // use oscillator.setNote to avoid having to do this calculation
        auto frequency = MidiMessage::getMidiNoteInHertz(message.getNoteNumber());
        
        oscPtr.load()->setGain(message.getFloatVelocity());

        oscPtr.load()->setFrequency(frequency);
    }
}

void Audio::audioDeviceIOCallback (const float** inputChannelData,
                                           int numInputChannels,
                                           float** outputChannelData,
                                           int numOutputChannels,
                                           int numSamples)
{
    //All audio processing is done here
    const float* inL = inputChannelData[0];

    float *outL = outputChannelData[0];
    float *outR = outputChannelData[1];
    
    while(numSamples--)
    {
        auto output = oscPtr.load()->nextSample();
        *outL = output;
        *outR = output;
        
        inL++;
        outL++;
        outR++;
    }
}


void Audio::audioDeviceAboutToStart (AudioIODevice* device)
{
    oscPtr.load()->setSampleRate(device->getCurrentSampleRate());
}

void Audio::audioDeviceStopped()
{

}

 int Audio::switchWaves (int ID)
{
    if (ID == 1)
    {
        oscPtr = &oscillatorSin;
    }
    else if (ID == 2)
    {
        oscPtr = &oscillatorSquare;
    }
    
    return ID;
}
