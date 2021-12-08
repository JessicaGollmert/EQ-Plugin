/*
 *  SinOscillator.cpp
 *  Software Development for Audio
 */

#pragma once

#include <JuceHeader.h>
#include "Oscillator.hpp"

/** Class for a sinewave oscillator with gain controls. Call nextSample() repetedly to stream audio samples from the oscilator. */

class SinOscillator : public Oscillator
{
public:
    SinOscillator() = default;
    ~SinOscillator() = default;
    
    virtual float renderWaveShape (float phase) override;
};
