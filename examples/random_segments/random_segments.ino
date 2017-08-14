/* Seven Segment Pixel library example code: random_segments

Displays random segments in random colors on a whole display.

created 2017
by Peter Hartmann
This example code is in the public domain.

<https://blog.hartmanncomputer.com>

*/

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

// How many delimeters are in the display?
#define NUMDELIMS 0

// How may pixels per delimeter are there?
#define PIXPERDELIM 0

// When we instatiate a display object we supply the number of digits in the
// custom built display,
// as well as the number of pixles per segment. Additionally we pass the ususal
// Adafruit_NeoPixel arguments\
// for object instatiation.

Seven_Segment_Pixel display1 =
    Seven_Segment_Pixel(DIGITS, PIXPERSEG, NUMDELIMS, PIXPERDELIM, NUMPIXELS,
                        PIN, NEO_GRB + NEO_KHZ800);

int delayval = 90; // delay for half a second

void setup() {
  display1.beginDisplay(); // This function is a wrapper for Adafruit_NeoPixel
                           // begin();
}

void loop() {
  for (int x = 1; x <= DIGITS; x++) {
    display1.updateDigit(x, random(11, 18), random(0, 255), random(0, 255),
                         random(0, 255));
  }
  display1.showDisplay();

  delay(delayval);
}
