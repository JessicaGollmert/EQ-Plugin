//
//  PlaybackGui.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 13/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//


#pragma once

#include <JuceHeader.h>
#include "../audio/FilePlayback.hpp"

/** Gui for the FilePlayer class */
class PlaybackGui :   public Component,
                        private Button::Listener,
                        private FilenameComponentListener
{
public:
    /** constructor - receives a reference to a FilePlayer object to control */
    PlaybackGui();
    
    /** Destructor */
    ~PlaybackGui();
    
    /** sets the file player that this gui controls */
    void setFilePlayer (FilePlayback* fp);
    
    //Component
    void resized() override;

private:
    //Button Listener
    void buttonClicked (Button* button) override;
    
    //FilenameComponentListener
    void filenameComponentChanged (FilenameComponent* fileComponentThatHasChanged) override;
    
    TextButton playButton   { "Play" };
    TextButton stopButton  { "Stop" };
    std::unique_ptr<FilenameComponent> fileChooser;
    
    FilePlayback* filePlayer  { nullptr };
};

