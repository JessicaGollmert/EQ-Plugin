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
                      public Button::Listener
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
    
    //Button Listener
    void buttonClicked (Button* button) override;

private:
    
    TextButton playButton   { "Play" };
    TextButton loadButton  { "Load" };
    
    FilePlayback* filePlayer  { nullptr };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlaybackGui)
};

