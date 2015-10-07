#ifndef SFML_MICROPHONE_H
#define SFML_MICROPHONE_H

#include <SFML/Audio/SoundRecorder.hpp>
#include "arduino/microphone.h"

class SfmlMicrophone : public sf::SoundRecorder, public Microphone {
public:
  SfmlMicrophone();
  int sample();
  bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);

private:
  int m_lastSample;
};

#endif