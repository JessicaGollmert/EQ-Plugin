/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent (Audio& a) :   audio (a)
{
    setSize (900, 600);
    
    waveSelector.setText("Wave Type Selector");
    waveSelector.setJustificationType(Justification::centred);
    waveSelector.addItem("Sine Wave", 1);
    waveSelector.addItem("Square Wave", 2);
    waveSelector.addListener(this);
    addAndMakeVisible(waveSelector);
    
    addAndMakeVisible(highPassGui);
}

MainComponent::~MainComponent()
{
    
}

//==============================================================================
void MainComponent::resized()
{
    waveSelector.setBounds(0, 0, getWidth(), 50);
    
    const auto paddingX = 5;
    const auto paddingY = 290;
    const auto width = 120;
    const auto height = getHeight();

    highPassGui.setBounds (paddingX, paddingY, width, height);
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
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

void MainComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    audio.switchWaves(waveSelector.getSelectedId());
}

