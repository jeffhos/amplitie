// main.cpp
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "sfml_strand.h"
#include "arduino/rainbow_display.h"

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

  // Create the displays to run on our strand
  RainbowDisplay rainbowDisplay(&strand);

  // Event loop
  sf::Clock clock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    if (clock.getElapsedTime().asMilliseconds() >= rainbowDisplay.updateTime()) {
      clock.restart();
      rainbowDisplay.update();
      strand.show();
    }
  }

  return 0;
}
