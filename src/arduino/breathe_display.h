///////////////////////////////////////////////////////////////////////////////
// breathe_display.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef BREATH_DISPLAY_H
#define BREATH_DISPLAY_H

#include "display.h"
#include "strand.h"

// Create a display where all LEDs "breathe" similar to the standby LED on Macs
class BreatheDisplay : public Display {
public:
  BreatheDisplay(Strand* strandP);
  void update();
  long updateTime();

private:
  Strand* m_strandP;
  unsigned int m_cycle;
  static const unsigned char PATTERN[];
};

#endif