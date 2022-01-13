

#include "HPF.hpp"

HighPassFilter::HighPassFilter()
{

}

HighPassFilter::~HighPassFilter()
{
    
}

void HighPassFilter::setFilter( float sampleRate, float frequency, float Q )
{
    highPassFilter.setCoefficients ( IIRCoefficients::makeLowPass (sampleRate, frequency, Q ) );
}

void HighPassFilter::applyFilter(float *samples, int numSamples)
{
    highPassFilter.processSamples ( samples, numSamples );
}

