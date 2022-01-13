//
//  LPFGui.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "LPFGui.hpp"
#include "FilterBase.hpp"

LPFGui::LPFGui(String name)
{
    componentName = name;
    frequencySlider.setNormalisableRange(NormalisableRange<double> { 8000.0f, 20000.0f, 0.01f, 0.6f } );
}

LPFGui::~LPFGui()
{
    
}