#include <PixelStrip.h>
#include <Wire.h>
#include "PulseAnimation.h"
#include "RedAnimation.h"
#include "IsaacGreenSpin.h"
#include "TargetSignalAnimation.h"

const int BRIGHTNESS = 128;

const int MAX_ANIMATIONS = 6;
const int MAX_PIXELSTRIPS = 4;
const int I2C_ADDRESS = 0x41;

const int IDLE_FIRE_ANIMATION = 0;
const int BLUE_ANIMATION = 1;
const int RED_ANIMATION = 2;
const int RED_PULSE_ANIMATION = 3;
const int SPIN_ANIMATION = 4;
const int TARGET_ANIMATION = 5;

const int BASE_STRIP = 0;
const int CLIMBER_STRIP = 1;
const int LEFT_SPINNER_STRIP = 2;
const int RIGHT_SPINNER_STRIP = 3;

PixelStrip *strip[MAX_PIXELSTRIPS];
Animation *animation[MAX_ANIMATIONS];
int wireTimeout = 0;

/**
   Change animations when I2C messages are received.
   When a message is received, the built-in LED will flash for a half second.
*/
void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // set up all Animations
  animation[IDLE_FIRE_ANIMATION] = new PulseAnimation();

  RedAnimation *blueAnimation = new RedAnimation();
  blueAnimation->color = BLUE;
  animation[BLUE_ANIMATION] = blueAnimation;

  RedAnimation *redAnimation = new RedAnimation();
  redAnimation->color = RED;
  animation[RED_ANIMATION] = redAnimation;

  PulseAnimation *redPulseAnimation = new PulseAnimation(4);
  redPulseAnimation->setColor(0, BLACK);
  redPulseAnimation->setColor(1, RED);
  redPulseAnimation->setColor(2, ORANGERED);
  redPulseAnimation->setColor(3, RED);
  animation[RED_PULSE_ANIMATION] = redPulseAnimation;

  animation[SPIN_ANIMATION] = new IsaacGreenSpin();

  TargetSignalAnimation *targeAnimation = new TargetSignalAnimation();
  animation[TARGET_ANIMATION] = targeAnimation;

  // set up all PixelStrips
  strip[BASE_STRIP] = new PixelStrip(new NEOPIXEL<7>, 8);
  strip[CLIMBER_STRIP] = new PixelStrip(new NEOPIXEL<6>, 8);
  strip[LEFT_SPINNER_STRIP] = new PixelStrip(new NEOPIXEL<5>, 8);
  strip[RIGHT_SPINNER_STRIP] = new PixelStrip(new NEOPIXEL<4>, 8);

  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->setAnimation(animation[3]);
    strip[s]->setBrightness(BRIGHTNESS);
    strip[s]->setup();
  }
  Serial.begin(9600);
}

void loop() {
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->draw();
    strip[s]->show();
  }
  delay(10);
  if (wireTimeout > 0 && millis() > wireTimeout)  {
    digitalWrite(LED_BUILTIN, LOW);
    wireTimeout = 0;
  }
}

/**
   Expects to receive two characters.
   The first character specifies the pixel strip number.
   The second character sets the animation number on that strip.
*/
void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    int s = Wire.read() - '0';
    int a = Wire.read() - '0';
    if (a >= 0 && a < MAX_ANIMATIONS) {
      strip[s]->setAnimation(animation[a]);
    } else {
      strip[s]->setAnimation(0);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    wireTimeout = millis() + 500;
    Serial.print("receiveEvent(");
    Serial.print(s); Serial.print(",");
    Serial.print(a); Serial.println(")");
  }
}
