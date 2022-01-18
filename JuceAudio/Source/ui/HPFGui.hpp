//
//  HPFGui.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 08/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
#include "../audio/HPF.hpp"
#include "FilterBase.hpp"

/** Class for the High-Pass Filter UI component. Uses the FilterGui base class */

class HPFGui : public FilterGui
{
public:
    /** Constructor */
    HPFGui(String name);
    /** Destructor */
    ~HPFGui();
    
    /** sets the hpf that this gui controls */
    void setHPF (HighPassFilter* hpfPtr) { hpf = hpfPtr; }
    
    /** callback to slider movement */
    void sliderValueChanged (Slider* slider) override;
        
private:
    /** pointer to an hpf object */
    HighPassFilter* hpf {nullptr};
};
