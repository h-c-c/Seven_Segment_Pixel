/*
  Seven_Segment_Pixel.cpp  - Library for driving obnoxiously
  large custom made 7 segment displays made with pixel strips.
  Created by Peter Hartmann, July 15, 2017.
  Released under GPLv3.
*/

#include "Seven_Segment_Pixel.h"
#include <../Adafruit_NeoPixel/Adafruit_NeoPixel.h>

//<<constructor>>
Seven_Segment_Pixel::Seven_Segment_Pixel(uint16_t digitsPerDisplay,
                                         uint16_t pixelsPerSegment,
                                         uint16_t numDelimiters,
                                         uint16_t pixPerDelimiter, uint16_t n,
                                         uint8_t p, uint8_t t)
    : digPerDisp(digitsPerDisplay), pixPerSeg(pixelsPerSegment),
      numDelims(numDelimiters), pixPerDelim(pixPerDelimiter) {
  strip = new Adafruit_NeoPixel(n, p, t);
}
//<<destructor>>
Seven_Segment_Pixel::~Seven_Segment_Pixel() {}

void Seven_Segment_Pixel::begin() { strip->begin(); }

void Seven_Segment_Pixel::show() { strip->show(); }

void Seven_Segment_Pixel::setPixelColor(uint16_t n, uint32_t c){
    strip->setPixelColor(n, c);}

void Seven_Segment_Pixel::updateDigit(uint16_t position, uint16_t digit,
                                      uint8_t RED, uint8_t GREEN,
                                      uint8_t BLUE) {

  bitmask = characterMap[digit];

  int charPos = 0;
  // expand bitbask to number of pixels per segment in the proper position
  for (int x = (position - 1) * 7; x <= (position - 1) * 7 + 6; x++) {

    if (bitmask.charAt(charPos) == '1') {
      // Lighting up this segment
      for (int pix = 0; pix <= pixPerSeg - 1; pix++) {
        strip->setPixelColor((x * pixPerSeg + pix),
                             strip->Color(RED, GREEN, BLUE));
      }

    } else {
      // Turning off this up this segment.
      for (int pix = 0; pix <= pixPerSeg - 1; pix++) {
        strip->setPixelColor((x * pixPerSeg + pix), 0);
      }
    }
    charPos++;
  }
}

void Seven_Segment_Pixel::updateDelimiter(uint16_t delimeter, uint8_t RED,
                                          uint8_t GREEN, uint8_t BLUE) {

  int digitsOffset = digPerDisp * pixPerSeg * 7;

  for (int pix = digitsOffset + delimeter * pixPerDelim - pixPerDelim;
       pix <= digitsOffset + delimeter * pixPerDelim; pix++) {
    strip->setPixelColor(pix, strip->Color(RED, GREEN, BLUE));
  }
}
