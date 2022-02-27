#ifndef IsaacGreenSpin_h
#define IsaacGreenSpin_h
#include <PixelStrip.h>

/**

*/
class IsaacGreenSpin : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    unsigned long color = GREEN;
  private:
};
#endif
