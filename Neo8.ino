#include <Adafruit_NeoPixel.h>

//declaring the neopixel strip
Adafruit_NeoPixel strip(64, 6);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.clear();
  strip.setBrightness(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  //a forloop for the colors 
  //starts at a color value of 0 and then increases by one until it reaches 255
  for (int x = 0; x <= 255; x++) {

    //a forloop for the number of pixels
    //starts at pixel index 0 and then increases by one until it reaches all 64 pixels
    for (int i = 0; i < strip.numPixels(); i++) {
      //the entire board lights up the color based on the X value (which should always be increasing) 
      strip.setPixelColor(i, Wheel((x)));
    }
    //placed here so the entire board shows same color at once
      strip.show();
      delay(10);
  }
}


//takes a value from 0-255 to get a color value
//the colors transition from red, green, blue back to red
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
