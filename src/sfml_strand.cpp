///////////////////////////////////////////////////////////////////////////////
// sfml_strand.cpp
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include "sfml_strand.h"

SfmlStrand::SfmlStrand(sf::RenderWindow* windowP, unsigned int numLeds)
  : m_windowP(windowP),
    m_leds(numLeds)
{
  for (int i = 0; i < numLeds; i++) {
    m_leds[i] = sf::CircleShape(25.0f);
    m_leds[i].setFillColor(sf::Color(0, 0, 0));
    m_leds[i].setPosition(0, 50 * i);
  }
}
  
void SfmlStrand::setColor(unsigned int n, Color color)
{
  m_leds[n].setFillColor(sf::Color(color.getRed(), color.getGreen(), color.getBlue()));
}

Color SfmlStrand::getColor(unsigned int n)
{
  sf::Color c = m_leds[n].getFillColor();
  return Color(c.r, c.g, c.b);
}

unsigned int SfmlStrand::getLength()
{
  return m_leds.size();
}

void SfmlStrand::show()
{
  m_windowP->clear();
  for (int i = 0; i < m_leds.size(); i++) {
    m_windowP->draw(m_leds[i]);
  }
  m_windowP->display();
}
