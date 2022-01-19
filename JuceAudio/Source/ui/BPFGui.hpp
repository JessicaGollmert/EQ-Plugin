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
    BPFGui ( Colour colour, String name, float minFreq, float maxFreq );
    
    /** Destructor */
    ~BPFGui();
    
    /** juce::Component function */
    void paint ( Graphics& ) override;
    
    /** juce::Component function */
    void resized () override;
    
    /** juce::Slider::Listener function */
    void sliderValueChanged ( Slider* slider ) override;
    
    /** juce::Button::Listener function */
    void buttonClicked ( Button* button ) override;
    
    /** Sets slider style and font of a slider and attached label
     @param slider
     @param label attached to slider */
    void setSliderAndLabel ( Slider& slider, Label& label );

    /** Converts slider value, in this case frequency, to a corresponding x value
     @param oldValue current slider value
     @param oldMax slider maximum value
     @param oldMin slider minimum value
     @param newMax new maximum of range to convert to
     @param newMin new minimum of range to convert to
     
     @return newValue*/
    float convertFreqToX ( float oldValue, float oldMax, float oldMin, float newMax, float newMin );
    
    /** Converts slider value, in this case Q, to a corresponding y value
     @see convertFreqToX()*/
    float convertGaintoY ( float oldValueY, float oldMaxY, float oldMinY, float newMaxY, float newMinY );

    /** Sets the bpf that this gui controls */
    void setBPF ( BandPassFilter* bpfPtr ) { bpf = bpfPtr; }
    
    /** Sets the audio object this gui controls */
    void setAudio ( Audio* aPtr ) { audio = aPtr; }
    
    /** Sliders public to be accessed by MainComponent */
    Slider frequencySlider;
    
    /** Sliders public to be accessed by MainComponent */
    Slider gainSlider;
    
private:
    /** Pointer to a bpf object */
    BandPassFilter* bpf { nullptr };
    
    /** Pointer to an audio object */
    Audio* audio { nullptr };
    
    /** Label attached to frequency slider*/
    Label frequencyLabel { "Freq", "Frequency" };
    
    /** Slider to control filter bandwidth q*/
    Slider qSlider;
    
    /** Label attached to q slider*/
    Label qLabel { "q", "Q" };
    
    /** Label attached to gain slider*/
    Label gainLabel { "Gain", "Gain" };
    
    /** Button for future addition of band on / off control*/
    TextButton bandOnOffButton { "OFF" };
    bool buttonOn = false;
    
    String componentName = "";
    Colour newColour;
};
