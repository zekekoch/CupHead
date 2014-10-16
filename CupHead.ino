#include "FastLED.h"

// How many leds are in the strip?
#define numLeds 144

#define pin1 10
#define pin2 11
#define pin3 9

#define strip1 65
#define strip2 62
#define strip3 17

// This is an array of leds.  One item for each led in your strip.
CRGB leds[numLeds];

#define numRows 9
byte stripLens[numRows] = {3, 9, 14, 18, 21, 23, 22, 19, 15};
byte stripStart[numRows] = {0, 3, 12, 26, 44, 65, 88, 110, 129};


// This function sets up the ledsand tells the controller about them
void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);

      FastLED.addLeds<WS2812B, pin1, RGB>(leds, strip1);
      FastLED.addLeds<WS2812B, pin2, RGB>(leds, strip1, strip2);
      FastLED.addLeds<WS2812B, pin3, RGB>(leds, strip1 + strip2, strip3);
      //FastLED.setDither( 0 );
      FastLED.setBrightness(255);
}

void lightRow(byte row)
{
  for(int i = stripStart[row];i<stripLens[row];i++)
  {
    leds[i] = CRGB::Red;
  }  
}

void bounceRows()
{
  FastLED.showColor(CRGB::Black);
  for(int i = 0;i<numRows;i++)
  {
    FastLED.showColor(CRGB::Black);
    lightRow(i);
    FastLED.show();
    delay(10);
  }
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() { 
  static uint8_t hue = 0;
  //FastLED.showColor(CRGB::White); 
  FastLED.showColor(CHSV(hue++, 255, 255)); 
  delay(100);
}
