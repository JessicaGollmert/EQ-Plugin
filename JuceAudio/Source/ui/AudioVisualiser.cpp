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
//void AudioVisualiser::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
//{
//    
//}
//
//void AudioVisualiser::releaseResources()
//{
//    
//}
//
//void AudioVisualiser::paint (Graphics& g)
//{
//    g.fillAll (juce::Colours::darkgrey);
//
//    g.setOpacity (1.0f);
//    g.setColour (juce::Colours::white);
//    drawFrame (g);
//}
//
//void AudioVisualiser::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill)
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
//
//void AudioVisualiser::pushNextSampleIntoFifo (float sample) noexcept
//{
//    // if the fifo contains enough data, set a flag to say
//    // that the next frame should now be rendered..
//    if (fifoIndex == fftSize)
//    {
//        if (! nextFFTBlockReady)
//        {
//            juce::zeromem (fftData, sizeof (fftData));
//            memcpy (fftData, fifo, sizeof (fifo));
//            nextFFTBlockReady = true;
//        }
//        
//        fifoIndex = 0;
//    }
//    
//    fifo[fifoIndex++] = sample;
//}
//
//   void AudioVisualiser::drawNextFrameOfSpectrum()
//   {
//       // first apply a windowing function to our data
//       window.multiplyWithWindowingTable (fftData, fftSize);
//
//       // then render our FFT data..
//       forwardFFT.performFrequencyOnlyForwardTransform (fftData);
//
//       auto mindB = -100.0f;
//       auto maxdB =    0.0f;
//
//       for (int i = 0; i < scopeSize; ++i)
//       {
//           auto skewedProportionX = 1.0f - std::exp (std::log (1.0f - (float) i / (float) scopeSize) * 0.2f);
//           auto fftDataIndex = juce::jlimit (0, fftSize / 2, (int) (skewedProportionX * (float) fftSize * 0.5f));
//           auto level = juce::jmap (juce::jlimit (mindB, maxdB, juce::Decibels::gainToDecibels (fftData[fftDataIndex])
//                                                              - juce::Decibels::gainToDecibels ((float) fftSize)),
//                                    mindB, maxdB, 0.0f, 1.0f);
//
//           scopeData[i] = level;
//       }
//   }
//
//void AudioVisualiser::timerCallback()
//{
//    if (nextFFTBlockReady)
//    {
//        drawNextFrameOfSpectrum();
//        nextFFTBlockReady = false;
//        repaint();
//    }
//}
//
//void AudioVisualiser::drawFrame (juce::Graphics& g)
//{
//    for (int i = 1; i < scopeSize; ++i)
//    {
//        auto width  = getLocalBounds().getWidth();
//        auto height = getLocalBounds().getHeight();
//        g.drawLine ({ (float) juce::jmap (i - 1, 0, scopeSize - 1, 0, width),
//                                juce::jmap (scopeData[i - 1], 0.0f, 1.0f, (float) height, 0.0f),
//                        (float) juce::jmap (i,     0, scopeSize - 1, 0, width),
//                                juce::jmap (scopeData[i],     0.0f, 1.0f, (float) height, 0.0f) });
//    }
//}
