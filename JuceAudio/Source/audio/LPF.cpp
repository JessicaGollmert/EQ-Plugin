//
//  LPF.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "LPF.hpp"

LowPassFilter::LowPassFilter()
{
    
}

LowPassFilter::~LowPassFilter()
{
    
}

void LowPassFilter::setFilter( float sampleRate, float frequency, float Q )
{
    lowPassFilter.setCoefficients ( IIRCoefficients::makeLowPass ( sampleRate, frequency, Q ) );
}

float LowPassFilter::applyFilter ( float sample )
{
    return lowPassFilter.processSingleSampleRaw (sample);
}
