#pragma once
#include <Arduino.h>

enum class LedMode {
  OFF,
  ON,
  BLINK_1HZ
};

class Led {
public:
  explicit Led(uint8_t pin);

  void init();
  void setMode(LedMode mode);
  void update();

private:
  uint8_t pin;
  LedMode mode;
  unsigned long lastToggle;
  bool state;
};
