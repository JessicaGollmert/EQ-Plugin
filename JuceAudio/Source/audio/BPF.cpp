//
//  BPF.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "BPF.hpp"

BandPassFilter::BandPassFilter()
{

}

BandPassFilter::~BandPassFilter()
{
    
}

void BandPassFilter::setFilter ( float sampleRate, float frequency, float Q )
{
    bandPassFilter.setCoefficients ( IIRCoefficients::makeBandPass ( sampleRate, frequency, Q ) );
}

float BandPassFilter::applyFilter ( float sample )
{
    return bandPassFilter.processSingleSampleRaw ( sample * gain );
}

void BandPassFilter::setGain ( float newGain )
{
    gain = newGain;
}
