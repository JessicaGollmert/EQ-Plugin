//
//  BPFGui.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 11/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
//#include "../audio/BPF.hpp"
#include "FilterBase.hpp"
#include "../audio/Audio.h"

/** Class for the Band-Pass Filter UI component. Does not use the FilterGui base class */

class BPFGui :   public Component,
                 public Slider::Listener,
                 public Button::Listener
{
public:
    /** Constructor */
    BPFGui(String name, float minFreq, float maxFreq);
    
    /** Destructor */
    ~BPFGui();
    
    /** sets the bpf that this gui controls */
    void setBPF (BandPassFilter* bpfPtr) { bpf = bpfPtr; }
    
    /** juce::Component function */
    void paint (juce::Graphics&) override;
    
    /** juce::Component function */
    void resized () override;
    
    /** juce::Slider::Listener function */
    void sliderValueChanged (Slider* slider) override;
    
    /** juce::Button::Listener function */
    void buttonClicked (Button* button) override;
    
    /** sets slider style and font of a slider and attached label
     @param slider
     @param label attached to slider */
    void setSliderAndLabel(Slider& slider, Label& label);

    /** converts slider value, in this case frequency, to a corresponding x value
     @param oldValue current slider value
     @param oldMax slider maximum value
     @param oldMin slider minimum value
     @param newMax new maximum of range to convert to
     @param newMin new minimum of range to convert to*/
    float convertFreqToX(float oldValue, float oldMax, float oldMin, float newMax, float newMin);
    
    /** converts slider value, in this case Q, to a corresponding y value
     @see convertFreqToX()*/
    float convertGaintoY(float oldValueY, float oldMaxY, float oldMinY, float newMaxY, float newMinY);
    
//    void setBPF(BandPassFilter* b) { bpf = b; }
    void setAudio(Audio* aPtr) { audio = aPtr; }
    
    /** Sliders public to be accessed by MainComponent */
    Slider frequencySlider;
    
    /** Sliders public to be accessed by MainComponent */
    Slider gainSlider;
    
private:
    /** pointer to an bpf object */
    BandPassFilter* bpf {nullptr};
    
    Label frequencyLabel { "Freq", "Frequency" };
    
    Slider qSlider;
    Label qLabel { "q", "Q" };
    
    Label gainLabel { "Gain", "Gain" };
    
    String componentName = "";
    
    TextButton bandOnOffButton { "OFF" };
    bool buttonOn = false;
    
    Audio* audio {nullptr};
};
