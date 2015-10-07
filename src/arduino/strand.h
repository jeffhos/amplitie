///////////////////////////////////////////////////////////////////////////////
// strand.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef STRAND_H
#define STRAND_H

#include "color.h"

// Generic representation of the "strand" of LEDs
class Strand {
public:
  virtual void setColor(unsigned int n, Color color) = 0;
  virtual Color getColor(unsigned int n) = 0;
  virtual unsigned int getLength() = 0;
  virtual void show() = 0;
};

#endif