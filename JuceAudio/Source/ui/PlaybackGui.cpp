//
//  PlaybackGui.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 13/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "PlaybackGui.hpp"

PlaybackGui::PlaybackGui()
{
    playButton.addListener (this);
    playButton.setColour (TextButton::buttonColourId, Colours::darkgrey);
    addAndMakeVisible (playButton);
    
    stopButton.addListener(this);
    stopButton.setColour (TextButton::buttonColourId, Colours::darkgrey);
    addAndMakeVisible(stopButton);
    
    AudioFormatManager formatManager;
    formatManager.registerBasicFormats();
    fileChooser = std::make_unique<FilenameComponent> ("audiofile",
                                                       File(),
                                                       true, false, false,
                                                       formatManager.getWildcardForAllFormats(),
                                                       String(),
                                                       "(select an audio file)");
    fileChooser->addListener (this);
    addAndMakeVisible (fileChooser.get());
}

PlaybackGui::~PlaybackGui()
{
    
}

//Component
void PlaybackGui::resized()
{
        playButton.setBounds(15, 280, 100, 50);
        stopButton.setBounds(785, playButton.getY(), 100, 50);
        fileChooser->setBounds (0, 0, getWidth(), 20);
}

//Button Listener
void PlaybackGui::buttonClicked (Button* button)
{
    if (filePlayer != nullptr && button == &playButton)
    {
        filePlayer->setPlaying( ! filePlayer->isPlaying());
        playButton.setColour (TextButton::buttonColourId, Colours::green);
        stopButton.setColour (TextButton::buttonColourId, Colours::darkgrey);
    }
    else if (filePlayer != nullptr && button == &stopButton)
    {
        filePlayer->setPlaying(false);
        stopButton.setColour (TextButton::buttonColourId, Colours::red);
        playButton.setColour (TextButton::buttonColourId, Colours::darkgrey);
    }
}

void PlaybackGui::setFilePlayer (FilePlayback* fp)
{
    filePlayer = fp;
}

//FilenameComponentListener
void PlaybackGui::filenameComponentChanged (FilenameComponent* fileComponentThatHasChanged)
{
    if (fileComponentThatHasChanged == fileChooser.get())
    {
        File audioFile (fileChooser->getCurrentFile().getFullPathName());
        
        if(filePlayer != nullptr && audioFile.existsAsFile())
        {
            filePlayer->loadFile(audioFile);
        }
        else
        {
            AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                         "sdaTransport",
                                         "Couldn't open file!\n\n");
        }
    }
}
