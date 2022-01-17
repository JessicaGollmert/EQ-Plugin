//
//  LPFGui.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
#include "../audio/LPF.hpp"
#include "FilterBase.hpp"

class LPFGui : public FilterGui
{
public:
    /** Constructor */
    LPFGui(String name);
    /** Destructor */
    ~LPFGui();

    /** sets the lpf that this gui controls */
    void setLPF (LowPassFilter* lpfPtr) { lpf = lpfPtr; }
    
    void sliderValueChanged (Slider* slider) override;
    
private:
    LowPassFilter* lpf {nullptr};  // pointer to an hpf object
};
