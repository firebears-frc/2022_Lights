#ifndef RedAnimation_h
#define RedAnimation_h
#include <PixelStrip.h>

class RedAnimation : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    unsigned long waitTime = 500;
    uint32_t color = RED;
  private:
    int pixelState = 0;
    int pixelNumA = 0;
    int pixelNumB = 1;
    int pixelNumC = 2;
    int i = 0;
};
#endif
