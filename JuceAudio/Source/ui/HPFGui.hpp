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

class HPFGui :   public Component,
                 public Slider::Listener
{
public:
    /** Constructor */
    HPFGui();
    /** Destructor */
    ~HPFGui();
    
    void setHPF (HighPassFilter* hpfPtr) { hpf = hpfPtr; }
        
    //Component
    void resized() override;
    //Slider::Listener
    void sliderValueChanged (Slider* slider) override;

    
private:
    HighPassFilter* hpf {nullptr};  //pointer to an hpf object
    
    Slider frequencySlider;
    Slider resonanceSlider;
//    Slider gain;
    
};
