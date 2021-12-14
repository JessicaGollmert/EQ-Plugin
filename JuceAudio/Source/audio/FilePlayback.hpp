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
class FilePlayback :  public AudioSource
{
public:
    /** Constructor */
    FilePlayback();
    
    /** Destructor */
    ~FilePlayback();
    
    /** Starts or stops playback of the looper */
    void setPlaying (bool newState);
    
    /** Gets the current playback state of the looper */
    bool isPlaying() const;
    
    /** Loads the specified file into the transport source */
    void loadFile (const File& newFile);
    
    //AudioSource
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void releaseResources() override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    
//    void setPosition (double newPosition);
    
private:
    std::unique_ptr<AudioFormatReaderSource> currentAudioFileSource;    //reads audio from the file
    AudioTransportSource audioTransportSource;            // this controls the playback of a positionable audio stream, handling the
                                                        // starting/stopping and sample-rate conversion
    TimeSliceThread thread;                             // thread for the transport source
};
