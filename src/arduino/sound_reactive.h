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
  // Length of buffer for dynamic level adjustment
  static const int SAMPLES = 60;

  // DC offset in mic signal - if unusure, leave 0
  static const int DC_OFFSET =  0;
  
  // Noise/hum/interference in mic signal
  static const int NOISE = 10;

  // Rate of peak falling dot
  static const int PEAK_FALL = 40;

  Strand* m_strandP;

  // Used for falling dot
  unsigned char m_peak = 0;

  // Frame counter for delaying dot-falling speed
  unsigned char m_dotCount = 0;

  // Frame counter for storing past volume data
  unsigned char m_volCount = 0;      
  
  // Collection of prior volume samples
  int m_vol[SAMPLES];
  
  // Current "dampened" audio level
  int m_lvl = 10;

  // For dynamic adjustment of graph low & high
  int m_minLvlAvg = 0;
  int m_maxLvlAvg = 512;
  
  Microphone* m_micP;
  int m_top;
};

#endif
