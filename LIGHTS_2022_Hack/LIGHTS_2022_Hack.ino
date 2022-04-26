#include <FastLED.h>
#define NUM_LEDS 80
CRGB leds[50];
unsigned long randomNum = 0;


void setup() {
  FastLED.addLeds<NEOPIXEL, 2>(leds, 33) // strip on front of electrical board
    .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, 3>(leds, 35) // strip on RSL light bar
    .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, 7>(leds, 25) // strip on Left side of Spinner
    .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, 11>(leds, 25) // strip on Right side of Spinner
    .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, 12>(leds, 46) // strip on Back of Shooter
    .setCorrection(TypicalLEDStrip);

}

void(* resetFunc) (void) = 0; //declare reset function @ address 0

void loop() {
    for (int pixel; pixel < NUM_LEDS; pixel = pixel + 2) {
      leds[pixel] = CRGB::Maroon;
      leds[pixel + 1] = CRGB::Blue;
    }
    FastLED.show();
    delay(800);
    for (int pixel; pixel < NUM_LEDS; pixel = pixel + 2) {
      leds[pixel] = CRGB::Green;
      leds[pixel + 1] = CRGB::Yellow;
    }
    FastLED.show();
    delay(300);
    for (int pixel; pixel < NUM_LEDS; pixel = pixel + 2) {
      leds[pixel] = CRGB::Maroon;
      leds[pixel + 1] = CRGB::Blue;
    }
    FastLED.show();
    delay(800);
    for (int pixel; pixel < NUM_LEDS; pixel = pixel + 2) {
      leds[pixel] = CRGB::DarkOrange;
      leds[pixel + 1] = CRGB::Magenta;
    }
    FastLED.show();
    delay(300);
    for (int pixel; pixel < NUM_LEDS; pixel = pixel + 2) {
      leds[pixel] = CRGB::Blue;
      leds[pixel + 1] = CRGB::Maroon;
    }
    FastLED.show();
    delay(800);
    for (int pixel; pixel < NUM_LEDS; pixel = pixel + 2) {
      leds[pixel] = CRGB::Yellow;
      leds[pixel + 1] = CRGB::Green;
    }
    FastLED.show();
    delay(300);
    for (int pixel; pixel < NUM_LEDS; pixel = pixel + 2) {
      leds[pixel] = CRGB::Blue;
      leds[pixel + 1] = CRGB::Maroon;
    }
    FastLED.show();
    delay(800);
    for (int pixel; pixel < NUM_LEDS; pixel = pixel + 2) {
      leds[pixel] = CRGB::Magenta;
      leds[pixel + 1] = CRGB::DarkOrange;
    }
    FastLED.show();
    delay(300);
    resetFunc();
}
