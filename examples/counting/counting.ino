/* Seven Segment Pixel library example code: counting 

Counts from 0 up the null character and back down using random colors on 
a whole display.

created 2017  
by Peter Hartmann
This example code is in the public domain.

<https://blog.hartmanncomputer.com>

*/

#include <Adafruit_NeoPixel.h>
#include <Seven_Segment_Pixel.h>


// Which pin on the Arduino is connected the NeoPixel display connected to?
#define PIN            6

// How many NeoPixels are in the seven segment display total?
#define NUMPIXELS      126

// How many digits are in the display?
#define DIGITS 6

// How may pixels per segement are there?
#define PIXPERSEG 3

// When we instatiate a display object we supply the number of digits in the custom built display,
// as well as the number of pixles per segment. Additionally we pass the ususal Adafruit_NeoPixel arguments\
// for object instatiation.

Seven_Segment_Pixel display1 = Seven_Segment_Pixel( DIGITS, PIXPERSEG, NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800 );

int delayval = 500; // delay for half a second

int increment = 1;

int count = 0;

void setup() {
  Serial.begin(115200);
  display1.beginDisplay();  // This function is a wrapper for Adafruit_NeoPixel begin();
}


void loop() {
  for (int x = 0; x<= DIGITS-1; x++) {
    display1.updateDigit(x, count, random(0,255),random(0,255), random(0,255));
  }
  display1.showDisplay();
  count = count + increment;

  if ( count == 0 || count == 10 ) {
    increment = -increment;
  }

  delay(delayval);
}
