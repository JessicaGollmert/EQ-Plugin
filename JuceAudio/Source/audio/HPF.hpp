//
//  HPF.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

/** Class to create a High-Pass Filter */

class HighPassFilter
{
    
public:
    /** Constructor */
    HighPassFilter();
    
    /** Destructor */
    ~HighPassFilter();
    
    /** sets the filter coefficients
    @param sampleRate current sample rate
    @param frequency cutoff frequency
    @param Q filter badnwidth*/
    void setFilter ( float sampleRate, float frequency, float Q );
    
    /** applies the filter to a spcified sample
    @param sample sample to apply filter to
     
     @return highPassFilter.processSingleSampleRaw (sample)*/
    float applyFilter ( float samples );
    
private:
    
    IIRFilter highPassFilter;
    
};
