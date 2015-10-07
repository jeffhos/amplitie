///////////////////////////////////////////////////////////////////////////////
// rainbow_display.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef RAINBOW_DISPLAY_H
#define RAINBOW_DISPLAY_H

#include "display.h"
#include "strand.h"

// Display that shows a slowly-changing rainbow of colors on the LEDs
class RainbowDisplay : public Display {
public:
  RainbowDisplay(Strand* strandP);
  void update();
  long updateTime();

private:
  Strand* m_strandP;
  unsigned int m_cycle;
  static const unsigned long UPDATE_TIME = 10;
};

#endif