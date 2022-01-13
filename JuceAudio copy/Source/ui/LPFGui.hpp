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

    void setLPF (LowPassFilter* lpfPtr) { lpf = lpfPtr; }

private:
    LowPassFilter* lpf {nullptr};  //pointer to an hpf object
};

