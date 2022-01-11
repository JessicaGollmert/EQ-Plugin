/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent (Audio& a)
: audio (a)
, highPassGui( "HPF" )
, lowPassGui( "LPF" )
, bandPassGui1 ( "Lows", 20.0f, 300.0f)
, bandPassGui2 ( "Mids", 300.0f , 3000.0f)
, bandPassGui3 ( "Highs", 3000.0f, 20000.0f)
{
    setSize (900, 700);
    
    playbackGui.setFilePlayer (audio.getFilePlayer());

    addAndMakeVisible (highPassGui);
    addAndMakeVisible (lowPassGui);
    addAndMakeVisible (bandPassGui1);
    addAndMakeVisible (bandPassGui2);
    addAndMakeVisible (bandPassGui3);
    
    addAndMakeVisible (playbackGui);
    
//    addAndMakeVisible(audioVisualiser);
}

MainComponent::~MainComponent()
{
    
}

//==============================================================================
void MainComponent::resized()
{
    const auto paddingXleft = 5;
    const auto paddingXright = paddingXleft + 770;
    const auto paddingY = 290;
    const auto filterOffsetY = paddingY + 50;
    const auto width = 120;
    const auto halfWidth = 60;
    const auto height = 310; // small component
    const auto largeHeight = 405; // large component

//    audioVisualiser.setBounds(0, 10, getWidth(), 270);
    
    highPassGui.setBounds (paddingXleft, filterOffsetY, width, height);
    
    lowPassGui.setBounds(paddingXright, filterOffsetY, width, height);
    
    bandPassGui1.setBounds(195, paddingY, width, largeHeight); // left
    bandPassGui2.setBounds(getWidth() / 2 - halfWidth, paddingY, width, largeHeight); // middle
    bandPassGui3.setBounds(585, paddingY, width, largeHeight); // right
    
    playbackGui.setBounds(0, 5, getWidth(), 330);
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
    g.setColour(Colours::lightblue);
    g.fillRoundedRectangle(0, 10, getWidth(), 270, 10);
}

//MenuBarCallbacks==============================================================
StringArray MainComponent::getMenuBarNames()
{
    auto names = { "Settings" };
    return StringArray (names);
}

PopupMenu MainComponent::getMenuForIndex (int topLevelMenuIndex, const String& menuName)
{
    PopupMenu menu;
    if (topLevelMenuIndex == 0)
    {
        menu.addItem(AudioPrefs, "Audio Prefrences", true, false);
    }
    return menu;
}

void MainComponent::menuItemSelected (int menuItemID, int topLevelMenuIndex)
{
    if (topLevelMenuIndex == FileMenu)
    {
        if (menuItemID == AudioPrefs)
        {
            DialogWindow::LaunchOptions la;
            la.dialogTitle = "Audio Settings";
            OptionalScopedPointer<Component> osp (std::make_unique<AudioDeviceSelectorComponent>
                                                  (audio.getAudioDeviceManager(),
                                                   1, 2, 2, 2,
                                                   true, true, true, false));
            osp->setSize (450, 350);
            la.content = std::move (osp);
            la.componentToCentreAround = this;
            la.launchAsync();
        }
    }
}
