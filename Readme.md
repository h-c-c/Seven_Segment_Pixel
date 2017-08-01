# Seven Segment Pixel

Seven Segment Pixel is a Arduino library to drive arbitrarily sized custom built 7 segment displays using the Adafruit NeoPixel library and compatible LED strips. 

Define your own display by specifying:
  1. the number of digits in your custom built display
  2. the number of pixels per segment

#### Usage:
Install this as you would other Arduino libraries. NB:you must also have the Adafruit NeoPixel library installed. In your sketch, it must be included along with this library.  See the example code for usage.  Instantiate multiple display objects for displays of different pixels per segment. 

#### Wiring
Pixels should be wired sequentially according to the traditional 7 segment designations [ABCDEFG].  For a display with 3 pixels per segment, segment A in the first digit should be wired with the first 3 pixels.  In other words the zeroth segment would contain pixels 0 1 and 2, etc.
