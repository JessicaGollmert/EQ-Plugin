//
//  HPF.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

class HighPassFilter
{
    
public:
    HighPassFilter();
    
    ~HighPassFilter();
    
    
    void setFilter ( float sampleRate, float frequency, float Q );
    
    float applyFilter (float samples);
    
private:
    
    IIRFilter highPassFilter;
    
};
