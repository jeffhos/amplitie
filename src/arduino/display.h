///////////////////////////////////////////////////////////////////////////////
// display.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef DISPLAY_H
#define DISPLAY_H

// Virtual display class that all display patterns for the tie should implement
class Display {
public:
  
  // Core function of each display: the driver code will call this repeatedly, updateTime() milliseconds apart, and the
  // display should update the LED strand each time it is called.
  virtual void update() = 0;

  // Should return the length of time (in milliseconds) the driver code should wait between calls to update()
  virtual long updateTime() = 0;
  
};

#endif