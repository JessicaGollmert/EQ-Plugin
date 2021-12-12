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
    frequencySlider.setNormalisableRange(NormalisableRange<double> { 0.0f, 8000.0f, 0.01f, 0.6f } );
    frequencySlider.setTextValueSuffix (" Hz");
    setSliderAndLabel(frequencySlider, frequencyLabel);
    
    resonanceSlider.setNormalisableRange(NormalisableRange<double> { 1.0f, 10.0f, 0.01f } );
    setSliderAndLabel(resonanceSlider, resonanceLabel);
}

HPFGui::~HPFGui()
{
    
}

void HPFGui::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (5);
    
    g.fillAll(Colours::darkred);
    g.setColour(Colours::white);
    g.setFont(20.0f);
    g.drawText("HPF", bounds.removeFromBottom (30.0f).withX (5), Justification::centred); //removeFromBottom
    g.drawRoundedRectangle(bounds.toFloat(), 1.0f, 2.0f);
}


void HPFGui::resized()
{
    const auto startY = 40;
    const auto startX = 10;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto LabelHeight = 20; // avoids "magic numbers"

    frequencySlider.setBounds(startX, startY, sliderWidth, sliderHeight);
    frequencyLabel.setBounds (frequencySlider.getX(), frequencySlider.getY() - labelYOffset, frequencySlider.getWidth(), LabelHeight);
    
    resonanceSlider.setBounds (startX, 170, sliderWidth, sliderHeight);
    resonanceLabel.setBounds (resonanceSlider.getX(), resonanceSlider.getY() - labelYOffset, resonanceSlider.getWidth(), LabelHeight);

}


void HPFGui::sliderValueChanged(Slider* slider)
{
    
}

void HPFGui::setSliderAndLabel(Slider& slider, Label& label)
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
