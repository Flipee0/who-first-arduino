#pragma once
#include <Arduino.h>

class Button {
public:
  explicit Button(uint8_t pin);

  void init();
  void update();
  bool wasPressed() const;

private:
  uint8_t pin;
  bool last;
  bool current;
  bool pressed;
};
