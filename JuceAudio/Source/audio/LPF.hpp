//
//  LPF.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

class LowPassFilter : public IIRFilter
{
    
public:
    LowPassFilter();
    
    ~LowPassFilter();
    
    
    void setType (dsp::StateVariableTPTFilterType newType);
    void setCutoffFrequency (float newFrequencyHz);
    void setResonance (float newResonance);
    
private:
    
};
