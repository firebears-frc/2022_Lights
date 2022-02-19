#include <PixelStrip.h>
#include "TargetSignalAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 144;
const int BRIGHTNESS = 40;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);
TargetSignalAnimation *animation;

void setup() {
  animation = new TargetSignalAnimation();
  animation->color = GREEN;
  //strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
  strip->setTimeout(0);
  strip->setup();
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
