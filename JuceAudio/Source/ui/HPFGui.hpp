//
//  HPFGui.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
#include "FilterBase.hpp"
#include "../audio/Audio.h"

/** Class for the High-Pass Filter UI component. Uses the FilterGui base class */

class HPFGui : public FilterGui
{
public:
    /** Constructor */
    HPFGui ( String name );
    /** Destructor */
    ~HPFGui();
    
    /** Sets the audio object that this gui controls */
    void setAudio ( Audio* aPtr ) { audio = aPtr; }
    
    /** Callback to slider movement */
    void sliderValueChanged ( Slider* slider ) override;
        
private:
    /** Pointer to an audio object */
    Audio* audio { nullptr };
};
