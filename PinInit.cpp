#include <Arduino.h>
#include "Config.h"
#include "PinInit.h"

void initPins() {
  for (size_t i = 0; i < TEAM_COUNT; ++i) {
    pinMode(teamLedPins[i], OUTPUT);
    digitalWrite(teamLedPins[i], LOW);
  }

  for (size_t i = 0; i < TEAM_COUNT; ++i) {
    pinMode(teamButtonPins[i], INPUT);
  }

  pinMode(START_SWITCH_PIN, INPUT);
  pinMode(RESET_ANSWER_PIN, INPUT);
}
