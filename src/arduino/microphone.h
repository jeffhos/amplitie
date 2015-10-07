///////////////////////////////////////////////////////////////////////////////
// microphone.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef MICROPHONE_H
#define MICROPHONE_H

// Virtual microphone class
class Microphone
{
public:
  // Should return an interger from 0-1024 representing the most recentl loudness measure on the microphone
  virtual int sample() = 0;
};

#endif