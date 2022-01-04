//
//  AudioVisualiser.hpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 14/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>

//class AudioVisualiser   : public Timer,
//                          public AudioAppComponent
//{
//public:
//    AudioVisualiser();
//
//    ~AudioVisualiser() override;
//
//    //==============================================================================
//    void prepareToPlay (int, double) override;
//    void releaseResources() override;
//
//    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
//
//    //==============================================================================
//    void paint (Graphics& g) override;
//
//    void timerCallback() override;
//
//    void pushNextSampleIntoFifo (float) noexcept;
//
//    void drawNextFrameOfSpectrum();
//    void drawFrame (Graphics&);
//    
//    enum
//    {
//        fftOrder  = 11,
//        fftSize   = 1 << fftOrder,
//        scopeSize = 512
//    };
//
//private:
//       dsp::FFT forwardFFT;                 
//       dsp::WindowingFunction<float> window;
//    
//       float fifo [fftSize];
//       float fftData [2 * fftSize];
//       int fifoIndex = 0;
//       bool nextFFTBlockReady = false;
//       float scopeData [scopeSize];
//    
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioVisualiser)
//};
