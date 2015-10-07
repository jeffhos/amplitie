///////////////////////////////////////////////////////////////////////////////
// sound_reactive.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef SOUND_REACTIVE_H
#define SOUND_REACTIVE_H

#include "display.h"
#include "strand.h"
#include "microphone.h"

class SoundReactive : public Display
{
public:
  SoundReactive(Strand* strandP, Microphone* micP);
  long updateTime();
  void update();

protected:
  Color Wheel(uint8_t wheelPos);
  
private:
  static const int SAMPLES = 60;   // Length of buffer for dynamic level adjustment
  const int DC_OFFSET =  0;   // DC offset in mic signal - if unusure, leave 0
  const int NOISE     = 10;   // Noise/hum/interference in mic signal
  const int PEAK_FALL = 40;   // Rate of peak falling dot

  Strand* m_strandP;
  unsigned char m_peak = 0;          // Used for falling dot
  unsigned char m_dotCount = 0;      // Frame counter for delaying dot-falling speed
  unsigned char m_volCount = 0;      // Frame counter for storing past volume data
  int m_vol[SAMPLES];       // Collection of prior volume samples
  int m_lvl = 10;           // Current "dampened" audio level
  int m_minLvlAvg = 0;      // For dynamic adjustment of graph low & high
  int m_maxLvlAvg = 512;
  Microphone* m_micP;
  int m_top;
};

#endif
