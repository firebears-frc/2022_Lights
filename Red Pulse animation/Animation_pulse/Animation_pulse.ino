#include <PixelStrip.h>
#include "PulseAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 24;
const int BRIGHTNESS = 128;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);
PulseAnimation *animation;

void setup() {
  animation = new PulseAnimation();
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
