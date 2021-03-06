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
    
    /** Sets the file player that this gui controls */
    void setFilePlayer ( FilePlayback* fp );
    
    /** juce::Component function */
    void resized() override;
    
    /** juce::Button::Listener function */
    void buttonClicked ( Button* button ) override;

private:
    /** Pointer to a filePlayer object */
    FilePlayback* filePlayer  { nullptr };
    
    /** Button to start or stop playback*/
    TextButton playButton   { "Play" };
    
    /** Button to load an audio file*/
    TextButton loadButton  { "Load" };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlaybackGui)
};

