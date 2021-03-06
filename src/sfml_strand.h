///////////////////////////////////////////////////////////////////////////////
// sfml_strand.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef SFML_STRAND_H
#define SFML_STRAND_H

#include <SFML/Graphics.hpp>
#include "arduino/strand.h"

class SfmlStrand : public Strand {
public:
  SfmlStrand(sf::RenderWindow* windowP, unsigned int numLeds);
  void setColor(unsigned int n, Color color);
  Color getColor(unsigned int n);
  unsigned int getLength();
  void show();

private:
  sf::RenderWindow* m_windowP;
  std::vector<sf::CircleShape> m_leds;
};

#endif
