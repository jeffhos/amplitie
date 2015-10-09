///////////////////////////////////////////////////////////////////////////////
// rule110_display.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef RULE110_DISPLAY_H
#define RULE110_DISPLAY_H

#include <vector>
#include "display.h"
#include "strand.h"

// Display that runs the "Rule 110" cellular automata (https://en.wikipedia.org/wiki/Rule_110) on the LEDs
class Rule110Display : public Display {
public:
  Rule110Display(Strand* strandP);
  void start();
  void update();
  long updateTime();

protected:
  bool getCell(int n);
  void init();

private:
  static const unsigned long UPDATE_TIME = 250L;
  static const unsigned int RESET_CYCLES = 200;
  static const unsigned char DARKEN_BY = 50;
  
  Strand* m_strandP;
  std::vector<bool> m_cells;
  unsigned int m_cycle;
};

#endif