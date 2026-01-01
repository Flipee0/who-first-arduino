#pragma once
#include "Button.h"
#include "Led.h"

enum class TeamState {
  ACTIVE,
  FALSE_START,
  ANSWERED,
  DISABLED
};

class Team {
public:
  Team(uint8_t buttonPin, uint8_t ledPin);

  void init();
  void update();

  bool pressed() const;

  void setState(TeamState s);
  TeamState getState() const;

  void setLed(LedMode mode);

private:
  Button button;
  Led led;
  TeamState state;
};
