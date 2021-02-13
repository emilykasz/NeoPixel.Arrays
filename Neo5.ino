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

  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 0, 0);
    delay(100);
    strip.show();
  }
  for (int i = 0; i< strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
    delay(100);
    strip.show();
  }
}

//statement that increases one by one turns on and then turns off
