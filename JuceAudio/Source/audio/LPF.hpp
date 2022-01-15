//
//  LPF.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

class LowPassFilter
{
    
public:
    LowPassFilter();
    
    ~LowPassFilter();
    
    
    void setFilter ( float sampleRate, float frequency, float Q );
    
    float applyFilter (float sample);
    
private:
    
    IIRFilter lowPassFilter;
};
