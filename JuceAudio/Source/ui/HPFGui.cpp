//
//  HPFGui.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "HPFGui.hpp"

HPFGui::HPFGui()
{
    frequencySlider.setSliderStyle(Slider::Rotary);
    frequencySlider.setNormalisableRange(NormalisableRange<double> { 0.0f, 1000.0f, 0.01f, 0.6f } );
    frequencySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 70, 25);
    frequencySlider.setTextValueSuffix (" Hz");
    frequencySlider.addListener(this);
    addAndMakeVisible(frequencySlider);
    
    frequencyLabel.setColour(Label::ColourIds::textColourId, Colours::white);
    frequencyLabel.setFont(15.0f);
    frequencyLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(frequencyLabel);
    
    resonanceSlider.setSliderStyle(Slider::Rotary);
    resonanceSlider.setNormalisableRange(NormalisableRange<double> { 1.0f, 10.0f, 0.01f } );
    resonanceSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 70, 25);
    resonanceSlider.addListener(this);
    addAndMakeVisible(resonanceSlider);
    
    resonanceLabel.setColour(Label::ColourIds::textColourId, Colours::white);
    resonanceLabel.setFont(15.0f);
    resonanceLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(resonanceLabel);
}

HPFGui::~HPFGui()
{
    
}

void HPFGui::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (5);
//    auto labelSpace = bounds.removeFromTop (25.0f);
    
    g.fillAll(Colours::darkred);
    g.setColour(Colours::white);
    g.setFont(20.0f);
    g.drawText("HPF", bounds.removeFromTop (25.0f).withX (5), Justification::centred);
    g.drawRoundedRectangle(bounds.toFloat(), 1.0f, 2.0f);
}


void HPFGui::resized()
{
    const auto startY = 55;
    const auto startX = 10;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto LabelHeight = 20; // avoids "magic numbers"

    frequencySlider.setBounds(startX, startY, sliderWidth, sliderHeight);
    frequencyLabel.setBounds (frequencySlider.getX(), frequencySlider.getY() - labelYOffset, frequencySlider.getWidth(), LabelHeight);
    
    resonanceSlider.setBounds (startX, 200, sliderWidth, sliderHeight);
    resonanceLabel.setBounds (resonanceSlider.getX(), resonanceSlider.getY() - labelYOffset, resonanceSlider.getWidth(), LabelHeight);

}


void HPFGui::sliderValueChanged(Slider* slider)
{
    
}
