#ifndef TargetSignalAnimation_h
#define TargetSignalAnimation_h
#include <PixelStrip.h>

class TargetSignalAnimation : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    unsigned long waitTime = 500;
    uint32_t color = GREEN;
  private:
    int pixelState = 0;
    int pixelNum = 0;
    int i = 0;
    int brightness = 40;
    uint32_t fadeColor(uint32_t c, int brightness);
};
#endif
