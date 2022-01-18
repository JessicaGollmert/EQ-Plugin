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
    frequencySlider.setNormalisableRange(NormalisableRange<double> { 20.0f, 20000.0f, 0.01f, 0.6f } );
    
}

HPFGui::~HPFGui()
{
    
}

void HPFGui::sliderValueChanged(Slider *slider)
{
//    if (this->hpf != nullptr)
//    {
//        this->hpf->setFilter(48000, frequencySlider.getValue(), qSlider.getValue());
        audio->setHPF(frequencySlider.getValue(), qSlider.getValue());
//    }
//    else
//    {
//        DBG("Pointer still null!");
//    }
}
