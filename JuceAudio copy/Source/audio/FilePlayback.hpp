//
//  FilePlayback.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 13/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

/** Simple FilePlayer class - strams audio from a file. */
class FilePlayback
{
public:
    /** Constructor */
    FilePlayback();
    
    /** Destructor */
    ~FilePlayback();
    
    /** Starts or stops playback of the looper */
    void setPlayState (bool newState);
    
    /** Gets the current playback state of the looper */
    bool isPlaying() const;
    
    /** Processes the audio sample by sample. */
    float processSampleL (float input);
    
//    float processSampleR (float input);
    
    /** Loads the specified file into the transport source */
    void load ();
    
    void setSamplerate (float samplerate);
    
    AudioBuffer<float> audioBuffer;
    
    unsigned int bufferPosition {0};
    
private:
    std::atomic<int> playState {false};

    float currentSamplerate = 0.0f;
};
