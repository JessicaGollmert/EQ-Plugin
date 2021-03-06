//
//  BPF.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

/** Class to create a Band-Pass Filter */

class BandPassFilter
{
    
public:
    /** Constructor */
    BandPassFilter();
    
    /** Destructor */
    ~BandPassFilter();

    /** sets the filter coefficients
    @param sampleRate current sample rate
    @param frequency cutoff frequency
    @param Q filter badnwidth*/
    void setFilter ( float sampleRate, float frequency, float Q );
    
    /** applies the filter to a spcified sample
    @param sample sample to apply filter to
     
    @return bandPassFilter.processSingleSampleRaw ( sample * gain )
     @see void setGain(float newGain) */
    float applyFilter ( float sample );
    
    /** Sets the filter band's gain */
    void setGain ( float newGain );
    
    /** Variable to be set by void setGain (float newGain) */
    float gain = 0.0f;
    
private:
    
    IIRFilter bandPassFilter;
    

};
