// color.cpp

#include "color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
{
  m_red = red;
  m_green = green;
  m_blue = blue;
}

Color Color::wheel(unsigned int pos)
{
  // Red -> orange
  if (pos < 128)
  {
    return Color(255, pos, 0);
  }
  
  // Orange -> yellow
  else if (pos < 256)
  {
    pos -= 128;
    return Color(255, 128 + pos, 0);
  }
  
  // Yellow -> green
  else if (pos < 384)
  {
    pos -= 256;
    return Color(255 - (pos * 2), 255, 0);
  }
  
  // Green -> blue
  else if (pos < 512)
  {
    pos -= 384;
    return Color(0, 255 - (pos * 2), pos * 2);
  }
  
  // Blue -> purple
  else if (pos < 640)
  {
    pos -= 512;
    return Color(pos * 2, 0, 255);
  }
  
  // Purple -> red
  else
  {
    pos -= 640;
    return Color(255, 0, 255 - (pos * 2));
  }
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

Color Color::darkenBy(unsigned char amount)
{
  return Color((m_red   > amount) ? m_red   - amount : 0,
               (m_green > amount) ? m_green - amount : 0,
               (m_blue  > amount) ? m_blue  - amount : 0);
}
