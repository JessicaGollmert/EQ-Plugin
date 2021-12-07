


#pragma once

#include <stdio.h>
#include "Oscillator.hpp"


class SquareOscillator : public Oscillator
{
public:
    SquareOscillator() = default;
    ~SquareOscillator() = default;
    
    virtual float renderWaveShape (float phase) override;
};


//float Oscillator::renderWaveShape (float currentPhase)
//{
//
//}
