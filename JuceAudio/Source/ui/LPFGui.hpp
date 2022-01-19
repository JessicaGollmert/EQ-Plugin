//
//  LPFGui.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
//#include "../audio/LPF.hpp"
#include "FilterBase.hpp"
#include "../audio/Audio.h"

/** Class for the Low-Pass Filter UI component. Uses the FilterGui base class */

class LPFGui : public FilterGui
{
public:
    /** Constructor */
    LPFGui ( String name );
    /** Destructor */
    ~LPFGui();

    /** Sets the audio object that this gui controls */
    void setAudio ( Audio* aPtr ) { audio = aPtr; }
    
    /** Callback to slider movement */
    void sliderValueChanged ( Slider* slider ) override;
    
private:
    /** Pointer to an audio object */
    Audio* audio { nullptr };
};
