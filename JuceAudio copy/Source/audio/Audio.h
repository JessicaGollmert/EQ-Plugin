/*
  ==============================================================================

    Audio.h
    Author:  Tom Mitchell

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <atomic>
#include "FilePlayback.hpp"
#include "BPF.hpp"
#include "LPF.hpp"
#include "HPF.hpp"


/** Class containing all audio processes */

class Audio :   public MidiInputCallback,
                public AudioIODeviceCallback
{
public:
    /** Constructor */
    Audio();
    
    /** Destructor */
    ~Audio();
    
    /** Returns the audio device manager, don't keep a copy of it! */
    AudioDeviceManager& getAudioDeviceManager() { return audioDeviceManager;}
    
    FilePlayback* getFilePlayer();
    
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    
    void audioDeviceIOCallback (const float** inputChannelData,
                                int numInputChannels,
                                float** outputChannelData,
                                int numOutputChannels,
                                int numSamples) override;
    void audioDeviceAboutToStart (AudioIODevice* device) override;
    void audioDeviceStopped() override;
    
    void updateFilters(float frequency, float q);
    
    float samplerate = 0.0f;
    
private:
    AudioDeviceManager audioDeviceManager;
//    AudioSourcePlayer audioSourcePlayer;
    FilePlayback filePlayer;
//    BandPassFilter bpf;
//    LowPassFilter lpf;
//    HighPassFilter hpf;
    IIRFilter hpf;
};