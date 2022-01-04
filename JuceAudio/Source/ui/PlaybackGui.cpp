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
    playButton.setColour (TextButton::buttonColourId, Colours::green);
    playButton.setColour (TextButton::buttonOnColourId, Colours::red);
    addAndMakeVisible (playButton);
    
    loadButton.addListener(this);
    loadButton.setColour (TextButton::buttonColourId, Colours::darkcyan);
    addAndMakeVisible(loadButton);
}

PlaybackGui::~PlaybackGui()
{
    
}

//Component
void PlaybackGui::resized()
{
        playButton.setBounds(15, 280, 100, 50);
        loadButton.setBounds(785, playButton.getY(), 100, 50);
}

//Button Listener
void PlaybackGui::buttonClicked (Button* button)
{
    if (filePlayer == nullptr)
    {
        return;
    }
    
    if (filePlayer != nullptr && button == &playButton)
    {
        filePlayer->setPlayState( ! filePlayer->isPlaying());
        playButton.setToggleState(filePlayer->isPlaying(), dontSendNotification);
        if (filePlayer->isPlaying())
        {
            playButton.setButtonText("Stop");
        }
        else
        {
            playButton.setButtonText("Play");
        }
    }
    else if (button == &loadButton)
    {
        if (filePlayer->isPlaying())
        {
            AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
                                             "Error", "Stop playback before loading", "OK",
                                             this);
        }
        else
        {
            filePlayer->load();
        }
    }
}

void PlaybackGui::setFilePlayer (FilePlayback* fp)
{
    filePlayer = fp;
}



