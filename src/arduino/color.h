///////////////////////////////////////////////////////////////////////////////
// color.h
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

// Class to represent a single RGP-specified color, along with a few ways of manipulating it
class Color {
public:
  // Maximum value that should be passed into wheel()
  static const unsigned int WHEEL_MAX = 768;

  // Constructor
  Color(unsigned char red, unsigned char green, unsigned char blue);
  
  // Returns a rainbow of colors around a color wheel as values from 0 to WHEEL_MAX are passed to it
  static Color wheel(unsigned int pos);

  // Return the red component of this color
  unsigned char getRed();

  // Return the green component of this color
  unsigned char getGreen();

  // Return the blue component of this color
  unsigned char getBlue();

  // Return a color with all components reduced by the indicated amount (stopping at 0 if amount is greater than the 
  // current value of any of the components)
  Color darkenBy(unsigned char amount);

private:
  unsigned char m_red;
  unsigned char m_green;
  unsigned char m_blue;
};
