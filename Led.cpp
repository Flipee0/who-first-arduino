#include "Led.h"
#include "Config.h"

Led::Led(uint8_t pin)
  : pin(pin), mode(LedMode::OFF),
    lastToggle(0), state(false) {}

void Led::init() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void Led::setMode(LedMode m) {
  mode = m;
  if (mode == LedMode::OFF) {
    digitalWrite(pin, LOW);
    state = false;
  }
  if (mode == LedMode::ON) {
    digitalWrite(pin, HIGH);
    state = true;
  }
}

void Led::update() {
  if (mode != LedMode::BLINK_1HZ) return;

  unsigned long now = millis();
  if (now - lastToggle >= BLINK_INTERVAL) {
    lastToggle = now;
    state = !state;
    digitalWrite(pin, state ? HIGH : LOW);
  }
}
