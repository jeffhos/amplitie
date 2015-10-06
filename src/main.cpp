// main.cpp
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

static const int NUM_LEDS = 16;

int main() 
{
  // Make this window do anti-aliasing
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  // Create the window
  sf::RenderWindow window(sf::VideoMode(50, 800), "Ampli-tie", sf::Style::Default, settings);
  
  // Create our LED circle objects
  std::vector<sf::CircleShape> leds(NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = sf::CircleShape(25.0f);
    leds[i].setFillColor(sf::Color(10 * i, 10 * i, 10 * i));
    leds[i].setPosition(0, 50 * i);
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    for (int i = 0; i < NUM_LEDS; i++) {
      window.draw(leds[i]);
    }
    window.display();
  }

  return 0;
}
