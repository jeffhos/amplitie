///////////////////////////////////////////////////////////////////////////////
// sound_reactive.cpp
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "sound_reactive.h"
#include "utils.h"

SoundReactive::SoundReactive(Strand* strandP, Microphone* micP)
{
  m_strandP = strandP;
  m_micP = micP;
  m_top = m_strandP->getLength() + 2;
  memset(m_vol, 0, sizeof(m_vol));
}


void SoundReactive::update()
{
  uint8_t  i;
  uint16_t minLvl, maxLvl;
  int      n, height;
  
  n   = m_micP->sample();                  // Raw reading from mic 
  n   = abs(n - 512 - DC_OFFSET);          // Center on zero
  n   = (n <= NOISE) ? 0 : (n - NOISE);    // Remove noise/hum
  m_lvl = ((m_lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = m_top * (m_lvl - m_minLvlAvg) / (long)(m_maxLvlAvg - m_minLvlAvg);

  // Clip output
  if (height < 0L) {
    height = 0;      
  } else if (height > m_top) {
    height = m_top;
  }

  // Color pixels based on rainbow gradient
  for (i = 0; i < m_strandP->getLength(); i++) {
    if (i >= height) {
      m_strandP->setColor(i, Color(0, 0, 0));
    } else {
      m_strandP->setColor(i, Wheel(map(i, 0, m_strandP->getLength() - 1, 30, 150)));
    }
  }
  
  // Update strip
  m_strandP->show(); 

  // Save sample for dynamic leveling
  m_vol[m_volCount] = n;                      
  if (++m_volCount >= SAMPLES) {
    m_volCount = 0; // Advance/rollover sample counter
  }

  // Get volume range of prior frames
  minLvl = maxLvl = m_vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (m_vol[i] < minLvl) {
      minLvl = m_vol[i];
    } else if (m_vol[i] > maxLvl) {
      maxLvl = m_vol[i];
    }
  }
  
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < m_top) {
    maxLvl = minLvl + m_top;
  }
  m_minLvlAvg = (m_minLvlAvg * 63 + minLvl) >> 6; // Dampen min/max levels
  m_maxLvlAvg = (m_maxLvlAvg * 63 + maxLvl) >> 6; // (fake rolling average)
}


long SoundReactive::updateTime() {
  return 0L;
}


// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
Color SoundReactive::Wheel(uint8_t wheelPos) {
  if (wheelPos < 85) {
    return Color(wheelPos * 3, 255 - wheelPos * 3, 0);
  } else if (wheelPos < 170) {
    wheelPos -= 85;
    return Color(255 - wheelPos * 3, 0, wheelPos * 3);
  } else {
    wheelPos -= 170;
    return Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
}
