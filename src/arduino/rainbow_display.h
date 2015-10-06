// rainbow_display.h

#ifndef RAINBOW_DISPLAY_H
#define RAINBOW_DISPLAY_H

#include "display.h"
#include "strand.h"

class RainbowDisplay : public Display {
public:
  RainbowDisplay(Strand* strandP);
  void update();
  long updateTime();

private:
  Strand* m_strandP;
  unsigned int m_cycle;
};

#endif