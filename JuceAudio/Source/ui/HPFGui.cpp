//
//  HPFGui.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "HPFGui.hpp"

HPFGui::HPFGui ( String name ) :
FilterGui ( Colours::darkred )

{
    componentName = name;
    frequencySlider.setNormalisableRange ( NormalisableRange<double> { 20.0f, 20000.0f, 0.1f, 0.6f } );
    
}

HPFGui::~HPFGui()
{
    
}

void HPFGui::sliderValueChanged ( Slider *slider )
{
    audio->setHPF ( frequencySlider.getValue(), qSlider.getValue() );
}
