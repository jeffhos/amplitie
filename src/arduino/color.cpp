// color.cpp

#include "color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
{
  m_red = red;
  m_green = green;
  m_blue = blue;
}

Color Color::Wheel(unsigned int pos)
{
  // Red -> orange
  if (pos < 256) {
    return Color(255, pos/2, 0);
  }

  // Orange -> yellow
  if (pos < 512) {
    return Color(255, pos/2, 0);
  }

  // Yellow -> green
  if (pos < 768) {
    pos = pos - 512;
    return Color(255 - pos, 255, 0);
  }

  // Green -> blue
  if (pos < 1024) {
    pos = pos - 768;
    if (pos < 128) {
      return Color(0, 255, pos*2);
    }
    pos = pos - 128;
    return Color(0, 255 - pos*2, 255);
  }

  // Blue -> purple
  if (pos < 1280) {
    pos = pos - 1024;
    return Color(pos, 0, 255);
  }

  // Purple -> red
  pos = pos - 1280;
  return Color(255, 0, 255 - pos);
}

unsigned char Color::getRed()
{
  return m_red;
}

unsigned char Color::getGreen()
{
  return m_green;
}

unsigned char Color::getBlue()
{
  return m_blue;
}
