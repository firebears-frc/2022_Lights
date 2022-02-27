#include "TargetSignalAnimation.h"


void TargetSignalAnimation::reset(PixelStrip *strip) {
  strip->begin();
  
}

void TargetSignalAnimation::draw(PixelStrip *strip) {
  if (strip->isTimedout()) {
    
    for(i = 0; i < 5; i++){
      pixelNum = random(strip->numPixels());
      brightness = random(0, 128);
      uint32_t newColor = fadeColor(color, brightness);
      strip->setPixelColor(pixelNum, newColor);
    }
    strip->setPixelColor(pixelNum, BLACK);
    setTimeout(10);
  }
}

uint32_t TargetSignalAnimation::fadeColor(uint32_t color, int brightness) {
      uint8_t r = (uint8_t)(color >> 16);
      uint8_t g = (uint8_t)(color >>  8);
      uint8_t b = (uint8_t)color;
      r = (uint8_t)( ((int)r * brightness / 256) );
      g = (uint8_t)( ((int)g * brightness / 256) );
      b = (uint8_t)( ((int)b * brightness / 256) );
      return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}
