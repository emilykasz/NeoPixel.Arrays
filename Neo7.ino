#include <Adafruit_NeoPixel.h>

//declaring the neopixel strip
Adafruit_NeoPixel strip(64, 6);

boolean flop = false;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.clear();
  strip.setBrightness(30);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < strip.numPixels(); i++) {
    if (i % 8 == 0) {
      flop = !flop;
    }
    flop=!flop;
    if (flop) {
      strip.setPixelColor(i, 255, 0, 0);
    }else {
        strip.setPixelColor(i, 0, 0, 0);
      }
    }
    strip.show();
    //flop = !flop;
    //delay(100);
  }
