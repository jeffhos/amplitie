#include "sfml_microphone.h"

SfmlMicrophone::SfmlMicrophone()
{
  m_lastSample = 0;
}

int SfmlMicrophone::sample()
{
  return m_lastSample;
}

bool SfmlMicrophone::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
  int leftSpan = std::numeric_limits<sf::Int16>::max() - std::numeric_limits<sf::Int16>::min();
  float valueScaled = (samples[sampleCount - 1] - std::numeric_limits<sf::Int16>::min()) / (float) leftSpan;

  m_lastSample = (unsigned int) valueScaled * 1024;

  return true;
}