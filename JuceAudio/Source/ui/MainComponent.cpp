/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent ( Audio& a )
: audio (a)
, highPassGui( "HPF" )
, lowPassGui( "LPF" )
, bandPassGui1 ( Colours::saddlebrown, "Lows", 20.0f, 300.0f )
, bandPassGui2 ( Colours::olive, "Mids", 300.0f , 3000.0f )
, bandPassGui3 ( Colours::darkgreen, "Highs", 3000.0f, 20000.0f )
{
    setSize ( 900, 700 );
    
    playbackGui.setFilePlayer ( audio.getFilePlayer() );

    addAndMakeVisible ( highPassGui );
    addAndMakeVisible ( lowPassGui );
    addAndMakeVisible ( bandPassGui1 );
    addAndMakeVisible ( bandPassGui2 );
    addAndMakeVisible ( bandPassGui3 );
    
    addAndMakeVisible ( playbackGui );
    
    lowPassGui.setAudio ( &audio );
    highPassGui.setAudio ( &audio );
    bandPassGui1.setAudio ( &audio );
    bandPassGui2.setAudio ( &audio );
    bandPassGui3.setAudio ( &audio );
    
    bandPassGui1.setBPF ( &audio.bpf[0] );
    bandPassGui2.setBPF ( &audio.bpf[1] );
    bandPassGui3.setBPF ( &audio.bpf[2] );
    
    for (int i = 0; i < 5; i++)
    {
        hertzValues[i].applyColourToAllText ( Colours::black );
        hertzValues[i].setColour ( TextEditor::ColourIds::backgroundColourId, Colours::lightblue );
        hertzValues[i].setReadOnly ( true );
        addAndMakeVisible ( hertzValues[i] );
    }
    hertzValues[0].setText ( "20Hz" );
    hertzValues[1].setText ( "100Hz" );
    hertzValues[2].setText ( "700Hz" );
    hertzValues[3].setText ( "3000Hz" );
    hertzValues[4].setText ( "20000Hz" );
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
    const auto componentWidth = 120;
    const auto halfComponentWidth = 60;
    const auto smallHeight = 310;        // LPF & HPF component
    const auto largeHeight = 405;        // BPF component
    const auto halfTotalWidth = getWidth() / 2;
    const auto bpfStartX = 195;
    const auto hzTextBoxY = 250;
    const auto textBoxHeight = 30;
    
    highPassGui.setBounds ( paddingXleft, filterOffsetY, componentWidth, smallHeight );
    
    lowPassGui.setBounds ( paddingXright, filterOffsetY, componentWidth, smallHeight );
    
    bandPassGui1.setBounds ( bpfStartX, paddingY, componentWidth, largeHeight );                                // left
    bandPassGui2.setBounds ( halfTotalWidth - halfComponentWidth, paddingY, componentWidth, largeHeight );      // middle
    bandPassGui3.setBounds ( bpfStartX * 3, paddingY, componentWidth, largeHeight );                            // right
    
    playbackGui.setBounds ( 0, 5, getWidth(), 330 );
    
    hertzValues[0].setBounds ( 2, hzTextBoxY, 45, textBoxHeight );                    // 20Hz
    hertzValues[1].setBounds ( 200, hzTextBoxY, 50, textBoxHeight );                  // 100Hz
    hertzValues[2].setBounds ( halfTotalWidth - 25, hzTextBoxY, 50, textBoxHeight );  // 700Hz
    hertzValues[3].setBounds ( 650, hzTextBoxY, 50, textBoxHeight );                  // 3000Hz
    hertzValues[4].setBounds ( getWidth() - 60, hzTextBoxY, 65, textBoxHeight );      // 20000Hz
    }

void MainComponent::paint ( Graphics& g )
{
    setValues();
    
    g.fillAll ( Colours::black );
    g.setColour ( Colours::skyblue );
    g.fillRoundedRectangle ( 0, 10, getWidth(), 270, 10 );
    
    g.setColour ( Colours::black );
    g.fillRect ( 0, 145, getWidth(), 3 );                                            // 0 dB line
                        
    const auto halfWidth = getWidth() / 2;
    const auto lineYPos = 10;
    const auto lineThickness = 2;
    const auto lineLength = 240;
    g.fillRect ( 10, lineYPos, lineThickness, lineLength);                           // 20Hz line
    g.fillRect ( halfWidth / 2, lineYPos, lineThickness, lineLength );               // 100Hz line
    g.fillRect ( halfWidth, lineYPos, lineThickness, lineLength );                   // 700Hz line
    g.fillRect ( halfWidth + getWidth() / 4, lineYPos, lineThickness, lineLength );  // 3000Hz line
    g.fillRect ( getWidth() - 10, lineYPos, lineThickness, lineLength );             // 20000Hz line
    
    const auto dotDiameter = 20;
    g.setColour ( Colours::saddlebrown );
    g.fillEllipse ( xValues[0], yValues[0], dotDiameter, dotDiameter );              // Lows 20 - 300
    g.setColour ( Colours::olive );
    g.fillEllipse ( xValues[1], yValues[1], dotDiameter, dotDiameter );              // Mids 300 - 3000
    g.setColour ( Colours::darkgreen );
    g.fillEllipse ( xValues[2], yValues[2], dotDiameter, dotDiameter );              // High 3000 - 20000
    
    const auto smallDotDiameter = 15;
    const auto dotYPosition = 135;
    g.setColour ( Colours::darkred );
    g.fillEllipse ( xValues[3], dotYPosition, smallDotDiameter, smallDotDiameter );   // HPF Cutoff
    g.setColour ( Colours::darkblue );
    g.fillEllipse ( xValues[4], dotYPosition, smallDotDiameter, smallDotDiameter );   // LPF Cutoff
    
    repaint();
}

//MenuBarCallbacks==============================================================
StringArray MainComponent::getMenuBarNames()
{
    auto names = { "Settings" };
    return StringArray (names);
}

PopupMenu MainComponent::getMenuForIndex ( int topLevelMenuIndex, const String& menuName )
{
    PopupMenu menu;
    if ( topLevelMenuIndex == 0)
    {
        menu.addItem ( AudioPrefs, "Audio Prefrences", true, false );
    }
    return menu;
}

void MainComponent::menuItemSelected ( int menuItemID, int topLevelMenuIndex )
{
    if ( topLevelMenuIndex == FileMenu )
    {
        if ( menuItemID == AudioPrefs )
        {
            DialogWindow::LaunchOptions la;
            la.dialogTitle = "Audio Settings";
            OptionalScopedPointer<Component> osp ( std::make_unique<AudioDeviceSelectorComponent>
                                                  (audio.getAudioDeviceManager(),
                                                   1, 2, 2, 2,
                                                   true, true, true, false ) );
            osp->setSize ( 450, 350 );
            la.content = std::move (osp);
            la.componentToCentreAround = this;
            la.launchAsync();
        }
    }
}

void MainComponent::setValues()
{
    xValues[0] = bandPassGui1.convertFreqToX ( bandPassGui1.frequencySlider.getValue(),
                                           bandPassGui1.frequencySlider.getMaximum(),
                                           bandPassGui1.frequencySlider.getMinimum(),
                                           323.0f,
                                           2.0f );
    
    xValues[1] = bandPassGui2.convertFreqToX ( bandPassGui2.frequencySlider.getValue(),
                                           bandPassGui1.frequencySlider.getMaximum(),
                                           bandPassGui1.frequencySlider.getMinimum(),
                                           334.5f,
                                           300.0f );
    
    xValues[2] = bandPassGui3.convertFreqToX ( bandPassGui3.frequencySlider.getValue(),
                                           bandPassGui1.frequencySlider.getMaximum(),
                                           bandPassGui1.frequencySlider.getMinimum(),
                                           624.0f,
                                           620.5f );
    
    xValues[3] = highPassGui.convertFreqToX ( highPassGui.frequencySlider.getValue(),
                                            highPassGui.frequencySlider.getMaximum(),
                                            highPassGui.frequencySlider.getMinimum(),
                                            880.f,
                                            2.0f );
    
    xValues[4] = lowPassGui.convertFreqToX ( lowPassGui.frequencySlider.getValue(),
                                           lowPassGui.frequencySlider.getMaximum(),
                                           lowPassGui.frequencySlider.getMinimum(),
                                           880.f,
                                           2.0f );
    
    yValues[0] = bandPassGui1.convertGaintoY ( bandPassGui1.gainSlider.getValue(),
                                          bandPassGui1.gainSlider.getMaximum(),
                                          bandPassGui1.gainSlider.getMinimum(),
                                          1.0f,
                                          269.0f );

    yValues[1] = bandPassGui2.convertGaintoY ( bandPassGui2.gainSlider.getValue(),
                                          bandPassGui2.gainSlider.getMaximum(),
                                          bandPassGui2.gainSlider.getMinimum(),
                                          1.0f,
                                          269.0f );

    yValues[2] = bandPassGui3.convertGaintoY ( bandPassGui3.gainSlider.getValue(),
                                          bandPassGui3.gainSlider.getMaximum(),
                                          bandPassGui3.gainSlider.getMinimum(),
                                          1.0f,
                                          269.0f );
}
