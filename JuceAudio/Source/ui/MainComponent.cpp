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
    
    for (int i = 0; i < 5; i++)
    {
        hertzValues[i].applyColourToAllText(Colours::black);
        hertzValues[i].setColour(TextEditor::ColourIds::backgroundColourId, Colours::lightblue);
        hertzValues[i].setReadOnly(true);
        addAndMakeVisible(hertzValues[i]);
    }
    hertzValues[0].setText("20Hz");
    hertzValues[1].setText("100Hz");
    hertzValues[2].setText("700Hz");
    hertzValues[3].setText("3000Hz");
    hertzValues[4].setText("20000Hz");
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

//    audioVisualiser.setBounds(3, 13, getWidth() - 6, 265);
    
    highPassGui.setBounds (paddingXleft, filterOffsetY, width, height);
    
    lowPassGui.setBounds(paddingXright, filterOffsetY, width, height);
    
    bandPassGui1.setBounds(195, paddingY, width, largeHeight); // left
    bandPassGui2.setBounds(getWidth() / 2 - halfWidth, paddingY, width, largeHeight); // middle
    bandPassGui3.setBounds(585, paddingY, width, largeHeight); // right
    
    playbackGui.setBounds(0, 5, getWidth(), 330);
    
    hertzValues[0].setBounds(2, 250, 45, 30); // 20Hz
    hertzValues[1].setBounds(200, 250, 50, 30); // 100Hz
    hertzValues[2].setBounds(getWidth() / 2 - 25, 250, 50, 30); // 700Hz
    hertzValues[3].setBounds(650, 250, 50, 30); // 3000Hz
    hertzValues[4].setBounds(getWidth() - 60, 250, 65, 30); // 20000Hz
}

void MainComponent::paint (Graphics& g)
{
    float x1 = bandPassGui1.convertFreqToX(bandPassGui1.frequencySlider.getValue(),
                                                  bandPassGui1.frequencySlider.getMaximum(),
                                                  bandPassGui1.frequencySlider.getMinimum(),
                                                  323.0f,
                                                  2.0f);
    
    float x2 = bandPassGui2.convertFreqToX(bandPassGui2.frequencySlider.getValue(),
                                                  bandPassGui1.frequencySlider.getMaximum(),
                                                  bandPassGui1.frequencySlider.getMinimum(),
                                                  334.5f,
                                                  300.0f);
    
    float x3 = bandPassGui3.convertFreqToX(bandPassGui3.frequencySlider.getValue(),
                                                  bandPassGui1.frequencySlider.getMaximum(),
                                                  bandPassGui1.frequencySlider.getMinimum(),
                                                  365.5f,
                                                  334.5f);
    
    
    g.fillAll (Colours::black);
    g.setColour(Colours::lightblue);
    g.fillRoundedRectangle(0, 10, getWidth(), 270, 10);
    
    g.setColour(Colours::black);
    g.fillRect(0, 270 / 2 + 10, getWidth(), 2); // 0 dB line
    
    g.fillRect(10, 10, 1, 240); // 20Hz
    g.fillRect((getWidth() / 2) / 2, 10, 1, 240); // 100Hz
    g.fillRect(getWidth() / 2, 10, 1, 240); // 700Hz
    g.fillRect((getWidth() / 2) + getWidth() / 4, 10, 1, 240); // 3000Hz
    g.fillRect(getWidth() - 10, 10, 1, 240); //20000Hz
    
    g.setColour(Colours::grey);
    g.fillEllipse(x1, 270 / 2, 20, 20); // Lows 20 - 300
    g.fillEllipse(x2, 270 / 2, 20, 20); // Mids 300 - 3000
    g.fillEllipse(x3, 270 / 2, 20, 20); // High 3000 - 20000
    
    repaint();
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

void MainComponent::sliderValueChanged (Slider* slider)
{
//    if (slider == &bandPassGui1.frequencySlider)
//    {
//        bandPassGui1.xMax = 300;
//        bandPassGui1.xMin = 10;
//        bandPassGui1.x1 = bandPassGui1.convertFreqToX(bandPassGui1.frequencySlider.getValue(), bandPassGui1.frequencySlider.getMaximum(), bandPassGui1.frequencySlider.getMinimum(), 300.0f, 10.0f);
//    }
//    else if (slider == &bandPassGui2.frequencySlider)
//    {
//        bandPassGui2.xMax = 650;
//        bandPassGui2.xMin = 300;
//    }
//    else if (slider == &bandPassGui3.frequencySlider)
//    {
//        bandPassGui3.xMax = 890;
//        bandPassGui3.xMin = 650;
//    }

}
