

#include "Oscillator.hpp"
#include <JuceHeader.h>
#include <cmath>

Oscillator::Oscillator()
{
    updatePhaseIncrement();
}

void Oscillator::setFrequency (float newFrequency)
{
    frequency = newFrequency;
    updatePhaseIncrement();
}

void Oscillator::setNote (int noteNumber)
{
    setFrequency (440.f * pow (2, (noteNumber - 69) / 12.0));
}

void Oscillator::setGain (float newGain)
{
    gain = newGain;
}

void Oscillator::setSampleRate (float newSampleRate)
{
    sampleRate = newSampleRate;
    updatePhaseIncrement();
}

float Oscillator::nextSample()
{
    auto out = renderWaveShape (phase) * gain ;
    
    phase += phaseIncrement;
    if(phase  > MathConstants<float>::twoPi)
        phase -= MathConstants<float>::twoPi;

    return out;
}

void Oscillator::updatePhaseIncrement()
{
    phaseIncrement = (MathConstants<float>::twoPi * frequency) / sampleRate;
}
