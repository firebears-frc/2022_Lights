#include "IsaacGreenSpin.h"

int pixelState = 0;

void IsaacGreenSpin::reset(PixelStrip *strip) {
  strip->begin();
  setTimeout(40);
}

void IsaacGreenSpin::draw(PixelStrip *strip) {
  if (isTimedout()) {
    strip->setPixelColor(0, (pixelState%3==0) ? RED : BLACK);
    pixelState = (pixelState + 1) % 3;
    for (int pixelNum = 0; pixelNum < strip->numPixels(); pixelNum++) {
      unsigned long pixelColor = ((pixelNum + pixelState) % 3 == 0) ? color : BLACK;
      strip->setPixelColor(pixelNum, pixelColor);
    }
    setTimeout(50);
  }
}
