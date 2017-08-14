/*
  Seven_Segment_Pixel.h - Library for driving obnoxiously
  large custom made 7 segment pixel displays.
  Created by Peter Hartmann, July 15, 2017.
  Released under GPLv3.
*/

#ifndef Seven_Segment_Pixel_H
#define Seven_Segment_Pixel_H

#include <../Adafruit_NeoPixel/Adafruit_NeoPixel.h>
#include <Arduino.h>

class Seven_Segment_Pixel {
public:
  Seven_Segment_Pixel(uint16_t digitsPerStrip, uint16_t pixelsPerSegment,
                      uint16_t numDelimiters, uint16_t pixPerDelimiter,
                      uint16_t n, uint8_t p, uint8_t t);
  ~Seven_Segment_Pixel();

  void beginDisplay(), showDisplay(),
      updateDigit(uint16_t position, uint16_t digit, uint8_t RED, uint8_t GREEN,
                  uint8_t BLUE),
      updateDelimiter(uint16_t delimeter, uint8_t RED, uint8_t GREEN,
                      uint8_t BLUE);

private:
  Adafruit_NeoPixel *strip;
  // 0,1,2,3,4,5,6,7,8,9 and null a character,
  // then array positions 11-17 are individual segments for funz.
  char *characterMap[18] = {
      "1111110", "0110000", "1101101", "1111001", "0110011", "1011011",
      "1011111", "1110000", "1111111", "1111011", "0000000", "1000000",
      "0100000", "0010000", "0001000", "0000100", "0000010", "0000001"};
  const uint16_t pixPerSeg, digPerDisp, numDelims, pixPerDelim;
  String bitmask;
};

#endif
