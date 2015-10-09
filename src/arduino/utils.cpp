///////////////////////////////////////////////////////////////////////////////
// utils.cpp
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include "utils.h"

#ifndef ARDUINO
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#endif