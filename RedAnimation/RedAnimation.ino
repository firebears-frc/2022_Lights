#include <PixelStrip.h>
#include "RedAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 144;
const int BRIGHTNESS = 128;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);
RedAnimation *animation;

void setup() {
  animation = new RedAnimation();
  animation->color = BLUE;
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
  strip->setTimeout(0);
  strip->setup();
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
