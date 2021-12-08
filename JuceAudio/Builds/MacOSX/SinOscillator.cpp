/*
 *  SinOscillator.cpp
 *  Software Development for Audio
 */

#include "SinOscillator.h"

float SinOscillator::renderWaveShape (float currentPhase)
{
    return std::sin (currentPhase);
}


