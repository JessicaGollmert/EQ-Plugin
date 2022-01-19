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
    AudioDeviceManager& getAudioDeviceManager() { return audioDeviceManager; }
    
    /** Returns a reference to a Fileplayer object*/
    FilePlayback* getFilePlayer();
    
    /** juce::MidiInputCallback function */
    void handleIncomingMidiMessage ( MidiInput* source, const MidiMessage& message ) override;
    
    /** juce::AudioIODeviceCallback function */
    void audioDeviceIOCallback ( const float** inputChannelData,
                                int numInputChannels,
                                float** outputChannelData,
                                int numOutputChannels,
                                int numSamples ) override;
    /** juce::AudioIODeviceCallback function */
    void audioDeviceAboutToStart ( AudioIODevice* device ) override;
    /** juce::AudioIODeviceCallback function */
    void audioDeviceStopped() override;
        
    /** Sets a filter's coefficients
     @param frequency
     @param q*/
    void setLPF ( float frequency, float q );
    
    /** @see void setLPF( float frequency, float q )*/
    void setHPF ( float frequency, float q );
    
    /** @see void setLPF( float frequency, float q )*/
    void setBPF ( float frequency, float q );
    
    /** Returns the spcified Bnad-Pass Filter from the bpf array*/
    BandPassFilter* getBPF ( int bandNumber) { return &bpf [bandNumber]; }
    
    /** Initialise samplerate to be 0 */
    float samplerate = 0.0f;
    
    /** Array of three BPFs for three frequency bands */
    BandPassFilter bpf [3];
    
private:
    AudioDeviceManager audioDeviceManager;
    FilePlayback filePlayer;

    LowPassFilter lpf;
    HighPassFilter hpf;
};
