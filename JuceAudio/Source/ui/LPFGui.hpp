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

class LPFGui :   public Component,
                 public Slider::Listener
{
public:
    /** Constructor */
    LPFGui();
    /** Destructor */
    ~LPFGui();
    
    void setLPF (LowPassFilter* lpfPtr) { lpf = lpfPtr; }
        
    void paint (juce::Graphics&) override;
    //Component
    void resized() override;
    //Slider::Listener
    void sliderValueChanged (Slider* slider) override;
    
    void setSliderAndLabel(Slider& slider, Label& label);

    
private:
    LowPassFilter* lpf {nullptr};  //pointer to an hpf object
    
    Slider frequencySlider;
    Label frequencyLabel { "Freq", "Fequency" }; // 1st ID, 2nd text shown
    
    Slider resonanceSlider;
    Label resonanceLabel { "Res", "Resonance" };
};
