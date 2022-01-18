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
#include "../ui/FilterBase.hpp"
//#include "../ui/BPFGui.hpp"

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
    
//    void setFilter (FilterGui* filterPtr) { filterGui = filterPtr; }
    
    void setLPF (float frequency, float q);
    void setHPF (float frequency, float q);
    void setBPF (float frequency, float q);
    
    BandPassFilter* getBPF(int bandNumber) { return &bpf [bandNumber]; }
    
    float samplerate = 0.0f;
    
private:
    AudioDeviceManager audioDeviceManager;
    FilePlayback filePlayer;
    BandPassFilter bpf [3];
    LowPassFilter lpf;
    HighPassFilter hpf;
    
//    FilterGui* filterGui {nullptr};  // pointer to a filterGui object
//    BPFGui* bpfGui {nullptr};  // pointer to a bpfGui object
};
