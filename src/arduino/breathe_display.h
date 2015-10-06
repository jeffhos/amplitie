// breathe_display.h

#ifndef BREATH_DISPLAY_H
#define BREATH_DISPLAY_H

#include "display.h"
#include "strand.h"

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