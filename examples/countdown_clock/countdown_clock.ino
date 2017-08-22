/* Seven Segment Pixel library example code: countdown_clock

Example code to show the delimeter feature. This sketch displays a 3 minute
countdown clock on a display with 3 digits and one colon which flashes when the
seconds change.

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
#define NUMPIXELS 65

// How many digits are in the display?
#define DIGITS 6

// How may pixels per segement are there?
#define PIXPERSEG 3

// How many delimeters are in the display?
#define NUMDELIMS 1

// How may pixels per delimeter are there?
#define PIXPERDELIM 2

// When we instatiate a display object we supply the number of digits in the
// custom built display, as well as the number of pixels per segment.
// Additionally we pass the ususal Adafruit_NeoPixel arguments for object
// instatiation.

Seven_Segment_Pixel display1 =
    Seven_Segment_Pixel(DIGITS, PIXPERSEG, NUMDELIMS, PIXPERDELIM, NUMPIXELS,
                        PIN, NEO_RGB + NEO_KHZ800);

uint8_t count = 180; // 3 minutes in seconds

void setup() {
  display1.begin(); // This function calls Adafruit_NeoPixel begin();
}

void loop() {

  uint8_t minutes = count / 60;
  uint8_t secondsTens = (count - minutes * 60) / 10; // Seconds tens place
  uint8_t secondsOnes =
      count - (minutes * 60) - (secondsTens * 10); // Seconds ones place

  display1.updateDigit(1, minutes, 255, 0, 0);
  display1.updateDigit(2, secondsTens, 255, 0, 0);
  display1.updateDigit(3, secondsOnes, 255, 0, 0);

  // Flash colon when seconds change
  if (!(secondsOnes % 2)) {
    //  even
    display1.updateDelimiter(1, 0, 0, 0);
  } else {
    //  odd
    display1.updateDelimiter(1, 255, 0, 0);
  }

  display1.show();

  delay(1000);
  count--;
  if (count == 0) {
    count = 180;
  }
}
