#ifndef GARLAND_H
#define GARLAND_H

#include <Arduino.h>
#include "Config.h"

class Garland {
public:
  Garland();

  void init();
  void update();
  void disable();
  void setMode(uint32_t mode);

private:
  uint32_t currentMode = 0;

  uint32_t lastUpdate = 0;
  uint16_t interval = 100;
  GarlandMode innerMode = garlandAllModes[0]; 
  uint32_t innerStageCount = 0;
  uint32_t currentInnerStage = 0;
  uint32_t lastInnerUpdate = 0;

  void allOff();
  void nextMode();
  void setInnerStages(GarlandMode mode, uint32_t count);
  void updateInnerStages();
};

#endif
