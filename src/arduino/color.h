// color.h

class Color {
public:
  Color(unsigned char red, unsigned char green, unsigned char blue);
  static Color wheel(unsigned int pos);
  unsigned char getRed();
  unsigned char getGreen();
  unsigned char getBlue();
  Color darkenBy(unsigned char amount);
  static const unsigned int WHEEL_MAX = 768;

private:
  unsigned char m_red;
  unsigned char m_green;
  unsigned char m_blue;
};