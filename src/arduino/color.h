// color.h

class Color {
public:
  Color(unsigned char red, unsigned char green, unsigned char blue);
  static Color Wheel(unsigned int pos);
  unsigned char getRed();
  unsigned char getGreen();
  unsigned char getBlue();

private:
  unsigned char m_red;
  unsigned char m_green;
  unsigned char m_blue;
};