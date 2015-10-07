#ifndef RULE110_DISPLAY_H
#define RULE110_DISPLAY_H

#include <vector>
#include "display.h"
#include "strand.h"

class Rule110Display : public Display {
public:
  Rule110Display(Strand* strandP);
  void update();
  long updateTime();

protected:
  bool getCell(int n);
  void init();

private:
  Strand* m_strandP;
  std::vector<bool> m_cells;
  unsigned int m_cycle;
  static const unsigned long UPDATE_TIME = 250L;
  static const unsigned int RESET_CYCLES = 200;
  static const unsigned char DARKEN_BY = 50;
};

#endif