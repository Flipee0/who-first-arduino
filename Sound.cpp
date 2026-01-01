#include "Sound.h"

Sound::Sound(uint8_t pin)
  : pin(pin), stopTime(0), active(false) {}

void Sound::init() {
  pinMode(pin, OUTPUT);
}

void Sound::play(uint16_t freq, uint32_t durationMs) {
  tone(pin, freq);
  stopTime = millis() + durationMs;
  active = true;
}

void Sound::update() {
  if (active && millis() >= stopTime) {
    noTone(pin);
    active = false;
  }
}

bool Sound::isPlaying() const {
  return active;
}
