//
//  FilePlayback.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 13/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "FilePlayback.hpp"

FilePlayback::FilePlayback() : thread ("FilePlayThread")
{
    thread.startThread();
}

FilePlayback::~FilePlayback()
{
    audioTransportSource.setSource (nullptr);   //unload the current file
    thread.stopThread (100);
}

void FilePlayback::setPlaying (bool newState)
{
    if(newState == true)
    {
        audioTransportSource.setPosition (0.0);
        audioTransportSource.start();
    }
    else
    {
        audioTransportSource.stop();
    }
}

bool FilePlayback::isPlaying () const
{
    return audioTransportSource.isPlaying();
}

void FilePlayback::loadFile(const File& newFile)
{
    // unload the previous file source and delete it..
    setPlaying (false);
    audioTransportSource.setSource (nullptr);
    
    // create a new file source from the file..
    // get a format manager and set it up with the basic types (wav, ogg and aiff).
    AudioFormatManager formatManager;
    formatManager.registerBasicFormats();
    
    if (auto reader = formatManager.createReaderFor (newFile))
    {
        //currentFile = audioFile;
        currentAudioFileSource = std::make_unique<AudioFormatReaderSource> (reader, true);
        
        // ..and plug it into our transport source
        audioTransportSource.setSource (currentAudioFileSource.get(),
                                   32768, // tells it to buffer this many samples ahead
                                   &thread,
                                   reader->sampleRate);
    }
}

//AudioSource
void FilePlayback::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    audioTransportSource.prepareToPlay (samplesPerBlockExpected, sampleRate);
}

void FilePlayback::releaseResources()
{
    audioTransportSource.releaseResources();
}

void FilePlayback::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    audioTransportSource.getNextAudioBlock (bufferToFill);
}

//void FilePlayback::setPosition(double newPosition)
//{
//    
//}

