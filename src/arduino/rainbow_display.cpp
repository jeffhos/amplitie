// rainbow_display.cpp

#include "rainbow_display.h"

RainbowDisplay::RainbowDisplay(Strand* strandP)
  : m_strandP(strandP)
{
  m_cycle = 0;
}

void RainbowDisplay::update()
{
  for (int i = 0; i < m_strandP->getLength(); i++) {
    unsigned int ledCycle = (m_cycle + (256 * i)) % 1536;
    m_strandP->setColor(i, Color::Wheel(ledCycle));
  }

  m_cycle++;
  if (m_cycle >= 1536) {
    m_cycle = 0;
  }
}

long RainbowDisplay::updateTime()
{
  return 10L;
}