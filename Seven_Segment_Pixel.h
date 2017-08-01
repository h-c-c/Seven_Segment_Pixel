/*
  Seven_Segment_Pixel.h - Library for driving obnoxiously
  large custom made 7 segment pixel displays.
  Created by Peter Hartmann, July 15, 2017.
  Released under GPLv3.
*/


    #ifndef Seven_Segment_Pixel_H
    #define Seven_Segment_Pixel_H

    #include <Arduino.h>
    #include <../Adafruit_NeoPixel/Adafruit_NeoPixel.h>


    class Seven_Segment_Pixel {
    public:
     Seven_Segment_Pixel(int digitsPerStrip, int pixelsPerSegment, uint16_t n, uint8_t p, uint8_t t);
     ~Seven_Segment_Pixel();

    void
      beginDisplay(),
      showDisplay(),
      updateDigit(int position, int digit, uint8_t RED , uint8_t GREEN, uint8_t BLUE);

    private:
       Adafruit_NeoPixel* strip;
       // 0,1,2,3,4,5,6,7,8,9 and null a character,
       // then array positions 11-17 are individual segments for funz.
       char* charMap[18] = { "1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "0011111", "1110000", "1111111", "1111011", "0000000", "1000000", "0100000", "0010000", "0001000", "0000100", "0000010", "0000001" };
       const uint16_t
         pixPerSeg,
         digPerDisp;
       String bitmask;

    };

    #endif