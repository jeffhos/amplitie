// strand.h

#ifndef STRAND_H
#define STRAND_H

#include "color.h"

class Strand {
public:
  virtual void setColor(unsigned int n, Color color) = 0;
  virtual unsigned int getLength() = 0;
  virtual void show() = 0;
};

#endif