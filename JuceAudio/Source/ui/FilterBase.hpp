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

/** Filter GUI base class to be used by HPF and LPF */

class FilterGui : public Component,
                  public Slider::Listener,
                  public Button::Listener
{
public:
    /** Filter constructor */
    FilterGui ( Colour colour );
    
    /** Filter destructor */
    virtual ~FilterGui() = default;
    
    /** juce::Component function */
    void paint ( Graphics& ) override;
    
    /** juce::Component function */
    void resized() override;
    
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
    float convertFreqToX( float oldValue, float oldMax, float oldMin, float newMax, float newMin );
    
    /** Sliders public to be accessed by MainComponent */
    Slider frequencySlider;
    
    /** Sliders public to be accessed by MainComponent */
    Slider qSlider;
    
    /** Bool to keep track of the EQ band on / off state */
    bool buttonOn = false;
    
protected:
    /** Label attached to frequency slider*/
    Label frequencyLabel { "Freq", "Frequency" };
    
    /** Label attached to q slider*/
    Label qLabel { "q", "Q" };
    
    /** Button for future addition of band on / off control*/
    TextButton bandOnOffButton { "OFF" };
    
    String componentName = "";
    
    Colour newColour;

};
