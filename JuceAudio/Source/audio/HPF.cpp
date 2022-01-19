//
//  HPF.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "HPF.hpp"

HighPassFilter::HighPassFilter()
{
    
}

HighPassFilter::~HighPassFilter()
{
    
}

void HighPassFilter::setFilter ( float sampleRate, float frequency, float Q )
{
    highPassFilter.setCoefficients ( IIRCoefficients::makeHighPass ( sampleRate, frequency, Q ) );
}

float HighPassFilter::applyFilter ( float sample )
{
    return highPassFilter.processSingleSampleRaw (sample);
}
