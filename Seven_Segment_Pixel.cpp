/*
  Seven_Segment_Pixel.cpp  - Library for driving obnoxiously
  large custom made 7 segment displays made with pixel strips.
  Created by Peter Hartmann, July 15, 2017.
  Released under GPLv3.
*/

#include "Seven_Segment_Pixel.h"
#include <../Adafruit_NeoPixel/Adafruit_NeoPixel.h>

//<<constructor>>
Seven_Segment_Pixel::Seven_Segment_Pixel(int digitsPerDisplay,
                                         int pixelsPerSegment, uint16_t n,
                                         uint8_t p, uint8_t t)
    : digPerDisp(digitsPerDisplay), pixPerSeg(pixelsPerSegment) {
  strip = new Adafruit_NeoPixel(n, p, t);
}
//<<destructor>>
Seven_Segment_Pixel::~Seven_Segment_Pixel() {}

void Seven_Segment_Pixel::beginDisplay() { strip->begin(); }

void Seven_Segment_Pixel::showDisplay() { strip->show(); }

void Seven_Segment_Pixel::updateDigit(int position, int digit, uint8_t RED,
                                      uint8_t GREEN, uint8_t BLUE) {

  bitmask = charMap[digit];

  int charPos = 0;
  // expand bitbask to number of pixels per segment in the proper position
  for (int x = position * 7; x <= position * 7 + 6; x++) {

    if (bitmask.charAt(charPos) == '1') {
      // Lighting up this segment
      for (int pix = 0; pix <= pixPerSeg; pix++) {
        strip->setPixelColor((x * pixPerSeg + pix),
                             strip->Color(RED, GREEN, BLUE));
      }

    } else {
      // Turning off this up this segment.
      for (int pix = 0; pix <= pixPerSeg; pix++) {
        strip->setPixelColor((x * pixPerSeg + pix), 0);
      }
    }
    charPos++;
  }
}
