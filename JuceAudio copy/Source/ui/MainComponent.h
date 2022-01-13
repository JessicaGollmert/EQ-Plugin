/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../audio/Audio.h"
#include "HPFGui.hpp"
#include "LPFGui.hpp"
#include "BPFGui.hpp"
#include "PlaybackGui.hpp"
#include "AudioVisualiser.hpp"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
                        public MenuBarModel
{
public:
    //==============================================================================
    /** Constructor */
    MainComponent (Audio& a);

    /** Destructor */
    ~MainComponent();

    //Comoponent====================================================================
    void resized() override;
    void paint (Graphics&) override;
    
    //MenuBarEnums/MenuBarModel=====================================================
    enum Menus
    {
        FileMenu = 0,
        
        NumMenus
    };
    
    enum FileMenuItems
    {
        AudioPrefs = 1,
        
        NumFileItems
    };
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex (int topLevelMenuIndex, const String& menuName) override;
    void menuItemSelected (int menuItemID, int topLevelMenuIndex) override;
    
private:
    Audio& audio;
    
    HPFGui highPassGui;
    LPFGui lowPassGui;
    BPFGui bandPassGui1;
    BPFGui bandPassGui2;
    BPFGui bandPassGui3;
    PlaybackGui playbackGui;
//    AudioVisualiser audioVisualiser;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};