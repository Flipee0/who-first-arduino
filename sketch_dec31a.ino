#include "Game.h"
#include "Garland.h"
#include "Config.h"
#include "Button.h"

Game game;
Garland garland;
Button garlandGameSwitch(GARLAND_GAME_SWITCH_PIN);

void setup() {
  garland.init();
  game.init();
}

void loop() {
  garlandGameSwitch.update();
  if (garlandGameSwitch.updated()) {
    garland.disable();
  }
  if (garlandGameSwitch.nowPressed()) {
    game.update();
  } else {
    garland.update();
  }
}
