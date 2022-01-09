//
//  HPFGui.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "HPFGui.hpp"

HPFGui::HPFGui(String name)
{
    componentName = name;
    frequencySlider.setNormalisableRange(NormalisableRange<double> { 0.0f, 8000.0f, 0.01f, 0.6f } );
}

HPFGui::~HPFGui()
{
    
}

