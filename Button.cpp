#include "Button.h"

Button::Button(uint8_t pin)
  : pin(pin), last(LOW), current(LOW), pressed(false) {}

void Button::init() {
  pinMode(pin, INPUT);
}

void Button::update() {
  current = digitalRead(pin);
  pressed = (last == LOW && current == HIGH);
  last = current;
}

bool Button::wasPressed() const {
  return pressed;
}
