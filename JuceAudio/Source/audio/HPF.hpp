//
//  HPF.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

class HighPassFilter : public IIRFilter
{
    
public:
    HighPassFilter();
    
    ~HighPassFilter();
    
    
    void setType (dsp::StateVariableTPTFilterType newType);
    void setCutoffFrequency (float newFrequencyHz);
    void setResonance (float newResonance);
    
private:
    
};
