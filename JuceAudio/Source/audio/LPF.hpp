//
//  LPF.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

/** Class to create a Low-Pass Filter */

class LowPassFilter
{
    
public:
    /** Constructor */
    LowPassFilter();
    
    /** Destructor */
    ~LowPassFilter();
    
    /** sets the filter coefficients
     @param sampleRate current sample rate
     @param frequency cutoff frequency
     @param Q filter badnwidth*/
    void setFilter ( float sampleRate, float frequency, float Q );
    
    /** Applies the filter to a spcified sample
     @param sample sample to apply filter to
     
     @return lowPassFilter.processSingleSampleRaw (sample)*/
    float applyFilter ( float sample );
    
private:
    
    IIRFilter lowPassFilter;
};
