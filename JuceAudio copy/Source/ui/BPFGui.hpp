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

class BPFGui :   public Component,
                 public Slider::Listener,
                 public Button::Listener
{
public:
    /** Constructor */
    BPFGui(String name, float minFreq, float maxFreq);
    /** Destructor */
    ~BPFGui();
    
    void setBPF (BandPassFilter* bpfPtr) { bpf = bpfPtr; }
    
    void paint (juce::Graphics&) override;
    
    void resized () override;
    
    void sliderValueChanged (Slider* slider) override;
    
    void setSliderAndLabel(Slider& slider, Label& label);
    
    void buttonClicked (Button* button) override;
    
private:
    BandPassFilter* bpf {nullptr};  //pointer to an hpf object
    
    Slider frequencySlider;
    Label frequencyLabel { "Freq", "Frequency" }; // 1st ID, 2nd text shown
    
    Slider resonanceSlider;
    Label resonanceLabel { "Res", "Resonance" };
    
    Slider gainSlider;
    Label gainLabel { "Gain", "Gain" };
    
    String componentName = "";
    
    TextButton bandOnOffButton { "OFF" };
    bool buttonOn = false;
};
