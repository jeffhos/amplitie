// rainbow_display.cpp

#include "rainbow_display.h"

RainbowDisplay::RainbowDisplay(Strand* strandP)
  : m_strandP(strandP)
{
  m_cycle = 0;
}

void RainbowDisplay::update()
{
  for (int i = 0; i < m_strandP->getLength(); i++)
  {
    // tricky math! we use each pixel as a fraction of the full 256-color wheel
    // (thats the i / strip.numPixels() part)
    // Then add in j which makes the colors go around per pixel
    // the % 256 is to make the wheel cycle around
    Color color = Color::wheel(((i * Color::WHEEL_MAX / m_strandP->getLength()) + 
      m_cycle) % Color::WHEEL_MAX);
    m_strandP->setColor(i, color);
  }  
  m_strandP->show();
  m_cycle++;
  if (m_cycle >= Color::WHEEL_MAX)
  {
    m_cycle = 0;
  }
}

long RainbowDisplay::updateTime()
{
  return UPDATE_TIME;
}