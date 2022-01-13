//
//  FilterBase.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 09/01/2022.
//  Copyright © 2022 UWE. All rights reserved.
//

#include "FilterBase.hpp"

FilterGui::FilterGui()
{
    frequencySlider.setTextValueSuffix (" Hz");
    setSliderAndLabel(frequencySlider, frequencyLabel);
    
    resonanceSlider.setNormalisableRange(NormalisableRange<double> { 1.0f, 10.0f, 0.01f } );
    setSliderAndLabel(resonanceSlider, resonanceLabel);
    
    bandOnOffButton.addListener (this);
    bandOnOffButton.setColour (TextButton::buttonColourId, Colours::darkgrey);
    addAndMakeVisible (bandOnOffButton);
}

void FilterGui::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (5);
    
    g.fillAll(Colours::darkred);
    g.setColour(Colours::white);
    g.setFont(20.0f);
    g.drawText(componentName, bounds.removeFromBottom (30.0f).withX (5), Justification::left);
    g.drawRoundedRectangle(bounds.toFloat(), 1.0f, 2.0f);
}


void FilterGui::resized()
{
    const auto startY = 40;
    const auto startX = 10;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto LabelHeight = 20; // avoids "magic numbers"
    const auto resonanceY = 170;
    const auto bounds = getLocalBounds();

    frequencySlider.setBounds(startX, startY, sliderWidth, sliderHeight);
    frequencyLabel.setBounds (frequencySlider.getX(), frequencySlider.getY() - labelYOffset, frequencySlider.getWidth(), LabelHeight);
    
    resonanceSlider.setBounds (startX, resonanceY, sliderWidth, sliderHeight);
    resonanceLabel.setBounds (resonanceSlider.getX(), resonanceSlider.getY() - labelYOffset, resonanceSlider.getWidth(), LabelHeight);
    
    bandOnOffButton.setBounds(bounds.getRight() - 63, bounds.getBottom() - 32, 60, 30);
}

void FilterGui::setSliderAndLabel(Slider& slider, Label& label)
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

void FilterGui::buttonClicked(Button *button)
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

    void FilterGui::sliderValueChanged (Slider* slider)
{
    
}
