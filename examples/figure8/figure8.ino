// Seven Segment Pixel library simple sketch (c) 2017 Peter Hartmann
// released under the GPLv3.

#include <Adafruit_NeoPixel.h>
#include <Seven_Segment_Pixel.h>

// Which pin on the Arduino is connected the NeoPixel display connected to?
#define PIN 6

// How many NeoPixels are in the seven segment display total?
#define NUMPIXELS 126

// How many digits are in the display?
#define DIGITS 6

// How may pixels per segement are there?
#define PIXPERSEG 3

// When we instatiate a display object we supply the number of digits in the
// custom built display,
// as well as the number of pixles per segment. Additionally we pass the ususal
// Adafruit_NeoPixel arguments\
// for object instatiation.

Seven_Segment_Pixel display1 = Seven_Segment_Pixel(DIGITS, PIXPERSEG, NUMPIXELS,
                                                   PIN, NEO_GRB + NEO_KHZ800);

int delayval = 300;

int count = 0;

void setup() {
  Serial.begin(115200);
  display1.beginDisplay(); // This function is a wrapper for Adafruit_NeoPixel
                           // begin();
}

int figure8[] = {17, 16, 11, 12, 17, 15, 14, 13};

void loop() {
  for (int x = 0; x <= DIGITS - 1; x++) {
    display1.updateDigit(x, figure8[count], random(0, 255), random(0, 255),
                         random(0, 255));
  }
  count++;
  display1.showDisplay();
  if (count == 8) {
    count = 0;
  }
  display1.showDisplay();

  delay(delayval);
}
