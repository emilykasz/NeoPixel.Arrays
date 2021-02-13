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
  for (int x = 0; x < 256; x++) {

    //a forloop for the number of pixels
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+x)));
    }
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
