//
//  FilePlayback.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 13/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "FilePlayback.hpp"

FilePlayback::FilePlayback()
{
    audioBuffer.setSize(2, 441000); // adjust to be flexible
    audioBuffer.clear();
}

FilePlayback::~FilePlayback()
{

}

void FilePlayback::setPlayState (bool newState)
{
    playState = newState;
}

bool FilePlayback::isPlaying () const
{
    return playState.load();
}

void FilePlayback::load ()
{
    AudioFormatManager formatManager;
    formatManager.registerBasicFormats();
    
    FileChooser chooser ("Please select the file you want to load...",
                         File::getSpecialLocation(File::userHomeDirectory),
                         formatManager.getWildcardForAllFormats());
    
    if (chooser.browseForFileToOpen())
    {
        File file (chooser.getResult());
        std::unique_ptr<AudioFormatReader> reader (formatManager.createReaderFor (file));
        
        if (reader != nullptr)
        {
            audioBuffer.setSize(reader->numChannels, (int)reader->lengthInSamples);
            reader->read (&audioBuffer, 0, (int)reader->lengthInSamples, 0, true, false);
        }
    }
}

float FilePlayback::processSample(float input)
{
    auto output = 0.0f;
//    float* audioSample;
    
    if (playState.load() == true)
    {
        //play
        output = *audioBuffer.getWritePointer(0, bufferPosition);
        
        // increment and cycle buffer
        if (++bufferPosition >= 441000)
        {
            bufferPosition = 0;
        }
    }
    return output;
}

//void FilePlayback::setPosition(double newPosition)
//{
//    
//}

