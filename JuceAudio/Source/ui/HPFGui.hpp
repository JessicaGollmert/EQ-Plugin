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
        
    void paint (juce::Graphics&) override;
    //Component
    void resized() override;
    //Slider::Listener
    void sliderValueChanged (Slider* slider) override;
    
    void setSliderAndLabel(Slider& slider, Label& label);

    
private:
    HighPassFilter* hpf {nullptr};  //pointer to an hpf object
    
    Slider frequencySlider;
    Label frequencyLabel { "Freq", "Frequency" }; // 1st ID, 2nd text shown
    
    Slider resonanceSlider;
    Label resonanceLabel { "Res", "Resonance" };
};
