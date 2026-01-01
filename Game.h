#pragma once
#include <Arduino.h>
#include "Team.h"
#include "Sound.h"
#include "Config.h"

enum class GameState {
  IDLE,               // п.1 — старт выкл
  WAIT_RANDOM_DELAY,  // п.2 / п.6 — случайная задержка
  PRE_SIGNAL,         // п.3 / п.9 — фальстарты
  SIGNAL,             // п.2 / п.6 — 1 кГц
  WAIT_ANSWER,        // п.4 — ждём первое нажатие
  ANSWER_LOCKED       // есть отвечающий
};

class Game {
public:
  Game();

  void init();
  void update();

private:
  GameState state;

  Team* teams[TEAM_COUNT];
  Sound sound;

  unsigned long stateStartTime;
  unsigned long randomDelay;

  int currentAnswerTeam;

  Button startSwitch;
  Button resetAnswerButton;

  void setState(GameState newState);
  void resetTeams();
  void detectFalseStarts();
  void detectFirstAnswer();

  bool startEnabled() const;
};
