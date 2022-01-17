//
//  FilterBase.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 09/01/2022.
//  Copyright © 2022 UWE. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <JuceHeader.h>

/** Class for a sinewave oscillator with gain controls. Call nextSample() repetedly to stream audio samples from the oscilator. */

class FilterGui : public Component,
                  public Slider::Listener,
                  public Button::Listener
{
public:
    /** Filter constructor */
    FilterGui();
    
    /** Filter destructor */
    virtual ~FilterGui() = default;
    
    void paint (juce::Graphics&) override;
    
    void resized() override;
    
    void sliderValueChanged (Slider* slider) override;
    
    void setSliderAndLabel(Slider& slider, Label& label);
    
    void buttonClicked (Button* button) override;
    
    float convertFreqToX();
    
    Slider frequencySlider;
    
    Slider qSlider;
    
protected:

    float x = 0.0;

    Label frequencyLabel { "Freq", "Frequency" }; // 1st ID, 2nd text shown
    
    Label qLabel { "Res", "Resonance" };
    
    String componentName = "";
    
    TextButton bandOnOffButton { "OFF" };
    bool buttonOn = false;
};
