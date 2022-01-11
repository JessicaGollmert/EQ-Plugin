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
    
    gainSlider.setNormalisableRange (NormalisableRange<double> { -12.0f, 12.0f, 0.01f } );// , 0.0f );
    gainSlider.setTextValueSuffix (" dB");
    setSliderAndLabel(gainSlider, gainLabel);
}

BPFGui::~BPFGui()
{
    
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
}
