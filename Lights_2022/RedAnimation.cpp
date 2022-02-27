#include "RedAnimation.h"


void RedAnimation::reset(PixelStrip *strip) {
  strip->begin();
  i = strip->numPixels();
}

void RedAnimation::draw(PixelStrip *strip) {
  if (strip->isTimedout()) {
    if(pixelNumA == i){
      pixelNumC = 2;
      pixelNumB = 1;
      pixelNumA = 0;
      i = i - 3;
    }
    for(int pixelNum = 0; pixelNum < i; pixelNum++){
      strip->setPixelColor(pixelNum, BLACK);
    }
    strip->setPixelColor(pixelNumC, color);
    strip->setPixelColor(pixelNumB, color);
    strip->setPixelColor(pixelNumA, color);
    pixelNumC = pixelNumC + 3;
    pixelNumB = pixelNumB + 3;
    pixelNumA = pixelNumA + 3;
    strip->show();
    strip->setTimeout(1);
  }
}
