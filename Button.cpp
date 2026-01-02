#include "Button.h"

Button::Button(uint8_t pin)
  : pin(pin), last(HIGH), current(HIGH), pressed(false) {}

void Button::init() {
  pinMode(pin, INPUT);
}

void Button::update() {
  current = digitalRead(pin);
  pressed = (last == HIGH && current == LOW);
  last = current;
}

bool Button::wasPressed() const {
  return pressed;
}

bool Button::nowPressed() const {
  return current == LOW;
}

bool Button::updated() const {
  return last != current;
}
