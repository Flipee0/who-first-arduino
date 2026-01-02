#pragma once
#include <Arduino.h>

class Button {
public:
  explicit Button(uint8_t pin);

  void init();
  void update();
  bool wasPressed() const;
  bool nowPressed() const;
  bool updated() const;

private:
  uint8_t pin;
  bool last;
  bool current;
  bool pressed;
};
