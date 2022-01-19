//
//  FilePlayback.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 13/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

/** Simple FilePlayer class - streams audio from a file. */
class FilePlayback
{
public:
    /** Constructor */
    FilePlayback();
    
    /** Destructor */
    ~FilePlayback();
    
    /** Starts or stops playback
     @param newState*/
    void setPlayState ( bool newState );
    
    /** Gets the current playback state*/
    bool isPlaying() const;
    
    /** Processes the audio sample by sample.
     @param input
     @return output*/
    float processSample ( float input );
    
    /** Loads the specified file*/
    void load ();
    
    /** Sets the sample rate
     @param samplerate*/
    void setSamplerate ( float samplerate );
    
    /** Initialise buffer position to be 0*/
    unsigned int bufferPosition {0};
    
private:
    /** Initialise playState to be false */
    std::atomic<int> playState {false};
    
    /** AudioBuffer object*/
    AudioBuffer<float> audioBuffer;
    
    /** initialise samplerate to be 0, to be set by void Audio::audioDeviceAboutToStart ( AudioIODevice* device )*/
    float currentSamplerate = 0.0f;
};
