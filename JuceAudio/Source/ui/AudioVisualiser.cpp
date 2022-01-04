//
//  AudioVisualiser.cpp
//  JuceAudio - App
//
//  Created by Jessica Gollmert on 14/12/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "AudioVisualiser.hpp"

//AudioVisualiser::AudioVisualiser() : forwardFFT (fftOrder),
//      window (fftSize, juce::dsp::WindowingFunction<float>::hann)
//{
//    setOpaque (true);
//    setAudioChannels (1, 1);
//    startTimerHz (30);
//    setSize (270, 700);
//}
//
//AudioVisualiser::~AudioVisualiser()
//{
//    shutdownAudio();
//}
//
//void AudioVisualiser::paint (Graphics& g)
//{
//    g.fillAll (juce::Colours::black);
//
//    g.setOpacity (1.0f);
//    g.setColour (juce::Colours::white);
//    drawFrame (g);
//}
//
//void AudioVisualiser::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
//{
//       {
//           if (bufferToFill.buffer->getNumChannels() > 0)
//           {
//               auto* channelData = bufferToFill.buffer->getReadPointer (0, bufferToFill.startSample);
//    
//               for (auto i = 0; i < bufferToFill.numSamples; ++i)
//                   pushNextSampleIntoFifo (channelData[i]);
//           }
//       }
//}
