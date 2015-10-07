///////////////////////////////////////////////////////////////////////////////
// main.cpp
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "sfml_strand.h"
// #include "arduino/sound_reactive.h"
#include "arduino/rainbow_display.h"
#include "arduino/breathe_display.h"
#include "arduino/rule110_display.h"

static const int NUM_LEDS = 16;

int main() 
{
  // Make this window do anti-aliasing
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  // Create the window
  sf::RenderWindow window(sf::VideoMode(50, 800), "Ampli-tie", sf::Style::Default, settings);
  
  // Create our virtual LED "strand"
  SfmlStrand strand(&window, NUM_LEDS);

  // Create our microphone reader
  // SfmlMicrophone mic;

  // Create the displays to run on our strand
  std::vector<Display*> displays;
  // displays.push_back(new SoundReactive(&strand, &mic))
  displays.push_back(new RainbowDisplay(&strand));
  displays.push_back(new BreatheDisplay(&strand));
  displays.push_back(new Rule110Display(&strand));
  int currentDisplay = 0;

  // Event loop
  sf::Clock clock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {
        currentDisplay++;
        if (currentDisplay >= displays.size()) {
          currentDisplay = 0;
        }
      }
    }

    if (clock.getElapsedTime().asMilliseconds() >= displays[currentDisplay]->updateTime()) {
      clock.restart();
      displays[currentDisplay]->update();
      strand.show();
    }
  }

  return 0;
}
