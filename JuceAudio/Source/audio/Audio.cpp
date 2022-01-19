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
    auto midiInputDevices = MidiInput::getAvailableDevices();
    if (midiInputDevices.size() > 0)
    {
        audioDeviceManager.setMidiInputDeviceEnabled ( midiInputDevices[0].identifier, true );
    }
    audioDeviceManager.addMidiInputCallback ( "", this );
    
    auto errorMessage = audioDeviceManager.initialiseWithDefaultDevices ( 1, 2 );
    if ( ! errorMessage.isEmpty() )
    {
        DBG (errorMessage);
    }
    audioDeviceManager.addAudioCallback (this);
}

Audio::~Audio()
{
    audioDeviceManager.removeAudioCallback (this);
    audioDeviceManager.removeMidiInputCallback ( "", this );
}

FilePlayback* Audio::getFilePlayer()
{
    return &filePlayer;
}

void Audio::handleIncomingMidiMessage ( MidiInput* source, const MidiMessage& message )
{
    if ( message.isNoteOnOrOff() )
    {
        if ( message.getVelocity() == 0 )
        {
            DBG ( "Note Off" );
        }
        else
        {
            DBG ( "Note On : Channel " << message.getChannel() << " , Note Number " << message.getNoteNumber() << " , Note in Hertz " << message.getMidiNoteInHertz ( message.getNoteNumber() ) << "Hz , Velocity " << message.getVelocity() );
        }
    }
}

void Audio::audioDeviceIOCallback ( const float** inputChannelData,
                                           int numInputChannels,
                                           float** outputChannelData,
                                           int numOutputChannels,
                                           int numSamples )
{
    //All audio processing is done here
    const float* inL = inputChannelData[0];

    float *outL = outputChannelData[0];
    float *outR = outputChannelData[1];
    
    while (numSamples--)
    {
        *outL = filePlayer.processSample (*outL);
        
        *outL = lpf.applyFilter (*outL);

        *outL = hpf.applyFilter (*outL);

        *outL = bpf[0].applyFilter (*outL);
        *outL = bpf[1].applyFilter (*outL);
        *outL = bpf[2].applyFilter (*outL);

        *outR = *outL;
        
        inL++;
        outL++;
        outR++;
    }
}

void Audio::audioDeviceAboutToStart ( AudioIODevice* device )
{
    samplerate = device->getCurrentSampleRate();
    filePlayer.setSamplerate (samplerate);
    bpf[0].setFilter ( samplerate, 100.f, 0.1f );
    bpf[1].setFilter ( samplerate, 300.f, 0.1f );
    bpf[2].setFilter ( samplerate, 3000.0f, 0.1f );
    lpf.setFilter ( samplerate, 2000.0f, 0.5f );
    hpf.setFilter ( samplerate, 100.0f, 0.5f );
}

void Audio::audioDeviceStopped()
{

}

void Audio::setLPF ( float frequency, float q )
{
    lpf.setFilter ( samplerate, frequency, q );
}

void Audio::setHPF ( float frequency, float q )
{
    hpf.setFilter(samplerate, frequency, q);
}

void Audio::setBPF ( float frequency, float q )
{
    for (int i = 0; i < 3; i++)
    {
        bpf[i].setFilter ( samplerate, frequency, q );
    }
}
