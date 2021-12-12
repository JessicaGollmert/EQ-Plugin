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

class BPFGui :   public Component,
                 public Slider::Listener
{
public:
    /** Constructor */
    BPFGui(String name, float minFreq, float maxFreq);
    /** Destructor */
    ~BPFGui();
    
    void setBPF (BandPassFilter* bpfPtr) { bpf = bpfPtr; }
        
    void paint (juce::Graphics&) override;
    //Component
    void resized() override;
    //Slider::Listener
    void sliderValueChanged (Slider* slider) override;
    
    void setSliderAndLabel(Slider& slider, Label& label);

    
private:
    BandPassFilter* bpf {nullptr};  //pointer to an hpf object
    
    Slider frequencySlider;
    Label frequencyLabel { "Freq", "Frequency" }; // 1st ID, 2nd text shown
    
    Slider resonanceSlider;
    Label resonanceLabel { "Res", "Resonance" };
    
    Slider gainSlider;
    Label gainLabel { "Gain", "Gain" };
    
    String componentName = "";
};
