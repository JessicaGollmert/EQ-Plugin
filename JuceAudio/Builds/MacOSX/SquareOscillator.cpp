

#include "SquareOscillator.hpp"

 float SquareOscillator::renderWaveShape (float currentPhase)
{    
    if (currentPhase < M_PI)
    {
        return -1.0;
    }
    else
    {
        return 1.0f;
    }
}
