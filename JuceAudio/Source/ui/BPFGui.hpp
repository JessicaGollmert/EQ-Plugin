//
//  BPFGui.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
#include "../audio/BPF.hpp"
#include "FilterBase.hpp"

class BPFGui :   public FilterGui
{
public:
    /** Constructor */
    BPFGui(String name, float minFreq, float maxFreq);
    /** Destructor */
    ~BPFGui();
    
    void setBPF (BandPassFilter* bpfPtr) { bpf = bpfPtr; }
    
    void resized ();
    
private:
    BandPassFilter* bpf {nullptr};  //pointer to an hpf object
    
    Slider gainSlider;
    Label gainLabel { "Gain", "Gain" };
};
