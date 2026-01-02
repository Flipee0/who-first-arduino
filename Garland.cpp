#include "Garland.h"

Garland::Garland() {
  currentMode = 0;
  lastUpdate = 0;
  interval = 100;
  innerMode = garlandAllModes[0]; 
  innerStageCount = 0;
  currentInnerStage = 0;
  lastInnerUpdate = 0;
}

void Garland::init() {
  for (uint8_t i = 0; i < TEAM_COUNT; i++) {
    pinMode(teamLedPins[i], OUTPUT);
    digitalWrite(teamLedPins[i], LOW);
  }
}

void Garland::setMode(uint32_t mode) {
  if (currentMode != mode) {
    currentMode = mode;
    lastUpdate = millis();
    allOff();
  }
}

void Garland::nextMode() {
  if (currentMode == GARLAND_MODES_COUNT - 1) {
    setMode(0);
  } else {
    setMode(currentMode + 1);
  }
}

void Garland::disable() {
  currentMode = 0;
  lastUpdate = millis();
  allOff();
}

void Garland::allOff() {
  for (uint8_t i = 0; i < TEAM_COUNT; i++) {
    digitalWrite(teamLedPins[i], LOW);
  }
}

void Garland::setInnerStages(GarlandMode mode, uint32_t count) {
  if (innerMode != mode) {
    innerStageCount = count;
    currentInnerStage = 0;
    lastInnerUpdate = millis();
    innerMode = mode;
  }
}

void Garland::updateInnerStages() {
  if (innerStageCount == 0) return;
  uint32_t now = millis();
  if ((now - lastInnerUpdate) >= (GARLAND_MODE_DURATION / innerStageCount)) {
    currentInnerStage++;
    lastInnerUpdate = now;
  }
}

void Garland::update() {
  uint32_t now = millis();
  if (now - lastUpdate >= GARLAND_MODE_DURATION) {
    nextMode();
  };
  updateInnerStages();

  switch (garlandAllModes[currentMode]) {
    case GarlandMode::RUN_FORWARD:
      setInnerStages(GarlandMode::RUN_FORWARD, 20);
      for (uint8_t i = 0; i < TEAM_COUNT; i++) {
        digitalWrite(teamLedPins[i], currentInnerStage == i ? HIGH : LOW);
      }
      break;
    case GarlandMode::RUN_BACKWARD:
      setInnerStages(GarlandMode::RUN_BACKWARD, 20);
      for (uint8_t i = 0; i < TEAM_COUNT; i++) {
        digitalWrite(teamLedPins[i], TEAM_COUNT - currentInnerStage - 1 == i ? HIGH : LOW);
      }
      break;
    case GarlandMode::BLINK:
      setInnerStages(GarlandMode::BLINK, BLINKS_COUNT);
      for (uint8_t i = 0; i < TEAM_COUNT; i++) {
        digitalWrite(teamLedPins[i], currentInnerStage % 2 == 0 ? LOW : HIGH);
      }
      break;
    case GarlandMode::RUN_COLORS:
      setInnerStages(GarlandMode::RUN_COLORS, GARLAND_TOTAL_COLORS);
      for (uint8_t i = 0; i < TEAM_COUNT; i++) {
        digitalWrite(teamLedPins[i], i % currentInnerStage == 0 ? HIGH : LOW);
      }
      break;
  }
}
