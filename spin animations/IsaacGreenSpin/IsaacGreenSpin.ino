#include <PixelStrip.h>
#include "IsaacGreenSpin.h"

const int PIN = 7;
const int NUM_PIXELS = 144;
const int BRIGHTNESS = 50;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);
IsaacGreenSpin *animation;

void setup() {
  animation = new IsaacGreenSpin();
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);

}
