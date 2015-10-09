///////////////////////////////////////////////////////////////////////////////
// sfml_microphone.cpp
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <limits>
#include "sfml_microphone.h"
#include "arduino/utils.h"

SfmlMicrophone::SfmlMicrophone()
{
  m_lastSample = 0;
}

int SfmlMicrophone::sample()
{
  return m_lastSample;
}

bool SfmlMicrophone::onStart()
{
  setProcessingInterval(sf::milliseconds(10));
  return true;
}

bool SfmlMicrophone::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
  m_lastSample = map(samples[sampleCount - 1], 
                     std::numeric_limits<sf::Int16>::min(),
                     std::numeric_limits<sf::Int16>::max(),
                     0,
                     1024);

  // std::cout << "Last sample is: " << m_lastSample << std::endl;

  return true;
}
