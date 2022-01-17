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

class HPFGui : public FilterGui
{
public:
    /** Constructor */
    HPFGui(String name);
    /** Destructor */
    ~HPFGui();
    
    void setHPF (HighPassFilter* hpfPtr) { hpf = hpfPtr; }
    
    void sliderValueChanged (Slider* slider) override;
        
private:
    HighPassFilter* hpf {nullptr};  //pointer to an hpf object
};
