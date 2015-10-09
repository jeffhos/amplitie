/*
 * LED VU meter for Arduino and Adafruit NeoPixel LEDs. More info: 
 * http://learn.adafruit.com/led-ampli-tie/
 *
 * Hardware requirements:
 *  - Most Arduino or Arduino-compatible boards (ATmega 328P or better).
 *  - Adafruit Electret Microphone Amplifier (ID: 1063)
 *  - Adafruit Flora RGB Smart Pixels (ID: 1260)
 *    OR
 *  - Adafruit NeoPixel Digital LED strip (ID: 1138)
 *  - Optional: battery for portable use (else power through USB or adapter)
 * Software requirements:
 *  - Adafruit NeoPixel library
 *
 * Connections:
 *  - 3.3V to mic amp +
 *  - GND to mic amp -
 *  - Analog pin to microphone output (configurable below)
 *  - Digital pin to LED data input (configurable below)
 *  See notes in setup() regarding 5V vs. 3.3V boards - there may be an
 *  extra connection to make and one line of code to enable or disable.
 *
 * Written by Adafruit Industries.  Distributed under the BSD license.
 * This paragraph must be included in any redistribution.
 */

#include <Adafruit_NeoPixel.h>
#include "display.h"
#include "strand.h"
#include "rainbow_display.h"
#include "sound_reactive.h"
#include "breathe_display.h"

class NeoPixelStrand : public Strand {
public:
  NeoPixelStrand(Adafruit_NeoPixel* strandP);
  void setColor(unsigned int n, Color color);
  Color getColor(unsigned int n);
  unsigned int getLength();
  void show();
  void begin();
private:
  Adafruit_NeoPixel* m_strandP;
};

NeoPixelStrand::NeoPixelStrand(Adafruit_NeoPixel* strandP)
{
  m_strandP = strandP;
}

void NeoPixelStrand::begin()
{
  m_strandP->begin();
}

void NeoPixelStrand::setColor(unsigned int n, Color color)
{
  m_strandP->setPixelColor(n, color.getRed(), color.getGreen(), color.getBlue());
}

Color NeoPixelStrand::getColor(unsigned int n)
{
  uint32_t color = m_strandP->getPixelColor(n);
  return Color(color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF);
}

unsigned int NeoPixelStrand::getLength()
{
  return m_strandP->numPixels();
}

void NeoPixelStrand::show()
{
  m_strandP->show();
}

class ArduinoMicrophone
{
public:
  ArduinoMicrophone(int micPin);
  int sample();

private:
  int m_micPin;
};

ArduinoMicrophone::ArduinoMicrophone(int micPin)
{
  m_micPin = micPin;
}

int ArduinoMicrophone::sample() 
{
  return analogRead(m_micPin);
}


// The debounce time; increase if the output flickers
static const long DEBOUNCE_DELAY = 50;     

// Number of pixels in strand
// static const int NUM_PIXELS = 16;
static const int NUM_PIXELS = 1;

// Microphone is attached to this analog pin
static const int MIC_PIN = A9;

// NeoPixel LED strand is connected to this pin
// static const int LED_PIN = 6;
static const int LED_PIN = 8;

// Which pin the mode button is connected to
static const int BUTTON_PIN = 12;

Adafruit_NeoPixel pixels(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
NeoPixelStrand strand(&pixels);

ArduinoMicrophone mic(MIC_PIN);

static const int NUM_DISPLAY_TYPES = 3;
Display* displays[NUM_DISPLAY_TYPES] = { 
  new SoundReactive(&strand, &mic),
  new RainbowDisplay(&strand),
  new BreatheDisplay(&strand),
  new Rule110Display(&strand);
};

// Index of the mode we're int
int mode = 1;

// The current reading from the input pin
int buttonState;

// The previous reading from the input pin
int lastButtonState = LOW;   

// The last time the output pin was toggled
long lastDebounceTime = 0;   

unsigned long now;
unsigned long lastUpdateTime = 0;


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  strand.begin();
}


void loop() {
  if (buttonPressed()) {
    mode++;
    if (mode == NUM_DISPLAY_TYPES) {
      mode = 0;
    }
    displays[mode]->start();
  }

  now = millis();
  if (now - lastUpdateTime >= displays[mode]->updateTime())
  {
    displays[mode]->update();
    lastUpdateTime = now;
  }
}


bool buttonPressed() {
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        return true;
      }
    }
  }

  return false;
}
