#pragma once
#include <Arduino.h>

class Sound {
public:
  explicit Sound(uint8_t pin);

  void init();
  void play(uint16_t freq, uint32_t durationMs);
  void update();
  bool isPlaying() const;

private:
  uint8_t pin;
  unsigned long stopTime;
  bool active;
};
