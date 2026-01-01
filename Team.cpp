#include "Team.h"

Team::Team(uint8_t buttonPin, uint8_t ledPin)
  : button(buttonPin), led(ledPin), state(TeamState::ACTIVE) {}

void Team::init() {
  button.init();
  led.init();
}

void Team::update() {
  button.update();
  led.update();
}

bool Team::pressed() const {
  return button.wasPressed();
}

void Team::setState(TeamState s) {
  state = s;
}

TeamState Team::getState() const {
  return state;
}

void Team::setLed(LedMode mode) {
  led.setMode(mode);
}
