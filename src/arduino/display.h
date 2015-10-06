// display.h

#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
public:
  virtual long updateTime() = 0;
  virtual void update() = 0;
};

#endif