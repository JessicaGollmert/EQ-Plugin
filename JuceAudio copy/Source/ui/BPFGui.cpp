//
//  BPFGui.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "BPFGui.hpp"

BPFGui::BPFGui(String name, float minFreq, float maxFreq)
{
    componentName = name;
    
    frequencySlider.setNormalisableRange (NormalisableRange<double> { minFreq, maxFreq, 0.01f, 0.6f } );
    frequencySlider.setTextValueSuffix (" Hz");
    setSliderAndLabel(frequencySlider, frequencyLabel);
    
    resonanceSlider.setNormalisableRange(NormalisableRange<double> { 1.0f, 10.0f, 0.01f } );
    setSliderAndLabel(resonanceSlider, resonanceLabel);
    
    gainSlider.setNormalisableRange (NormalisableRange<double> { -12.0f, 12.0f, 0.01f } );// , 0.0f );
    gainSlider.setTextValueSuffix (" dB");
    setSliderAndLabel(gainSlider, gainLabel);
    
    bandOnOffButton.addListener (this);
    bandOnOffButton.setColour (TextButton::buttonColourId, Colours::darkgrey);
    addAndMakeVisible (bandOnOffButton);
}

BPFGui::~BPFGui()
{
    
}

void BPFGui::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (5);

    g.fillAll(Colours::darkred);
    g.setColour(Colours::white);
    g.setFont(20.0f);
    g.drawText(componentName, bounds.removeFromBottom (30.0f).withX (5), Justification::left);
    g.drawRoundedRectangle(bounds.toFloat(), 1.0f, 2.0f);
}

void BPFGui::resized()
{
    const auto startY = 30;
    const auto startX = 10;
    const auto resonanceY = 150;
    const auto gainY = 270;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto LabelHeight = 20;

    frequencySlider.setBounds(startX, startY, sliderWidth, sliderHeight);
    frequencyLabel.setBounds (frequencySlider.getX(), frequencySlider.getY() - labelYOffset,
                              frequencySlider.getWidth(), LabelHeight);

    resonanceSlider.setBounds (startX, resonanceY, sliderWidth, sliderHeight);
    resonanceLabel.setBounds (resonanceSlider.getX(), resonanceSlider.getY() - labelYOffset,
                              resonanceSlider.getWidth(), LabelHeight);

    gainSlider.setBounds(startX, gainY, sliderWidth, sliderHeight);
    gainLabel.setBounds(gainSlider.getX(), gainSlider.getY() - labelYOffset, gainSlider.getWidth(), LabelHeight);
    
    bandOnOffButton.setBounds(getLocalBounds().getRight() - 63, getLocalBounds().getBottom() - 32, 60, 30);
}

void BPFGui::sliderValueChanged(Slider* slider)
{

}

void BPFGui::setSliderAndLabel(Slider& slider, Label& label)
{
    slider.setSliderStyle(Slider::Rotary);
    slider.setTextBoxStyle(Slider::TextBoxBelow, false, 70, 25);
    slider.addListener(this);
    addAndMakeVisible(slider);

    label.setColour(Label::ColourIds::textColourId, Colours::lightgreen);
    label.setFont(15.0f);
    label.setJustificationType(Justification::centred);
    addAndMakeVisible(label);
}

void BPFGui::buttonClicked(Button *button)
{
    if (button == &bandOnOffButton && buttonOn == false)
    {
        buttonOn = true;
        bandOnOffButton.setButtonText( "ON" );
        bandOnOffButton.setColour (TextButton::buttonColourId, Colours::lightgrey);
    }
    else if (button == &bandOnOffButton && buttonOn == true)
    {
        buttonOn = false;
        bandOnOffButton.setButtonText( "OFF" );
        bandOnOffButton.setColour (TextButton::buttonColourId, Colours::darkgrey);
    }
}
