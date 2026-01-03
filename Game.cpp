#include "Game.h"

Game::Game()
  : state(GameState::IDLE),
    sound(SOUND_PIN),
    currentAnswerTeam(-1),
    startSwitch(START_SWITCH_PIN),
    resetAnswerButton(RESET_ANSWER_PIN) {

  for (uint8_t i = 0; i < TEAM_COUNT; ++i) {
    teams[i] = new Team(teamButtonPins[i], teamLedPins[i]);
  }
}

void Game::init() {
  randomSeed(0);

  startSwitch.init();
  resetAnswerButton.init();
  sound.init();

  for (auto &team : teams) {
    team->init();
  }

  resetTeams();
}

void Game::update() {
  unsigned long now = millis();

  startSwitch.update();
  resetAnswerButton.update();

  for (auto &team : teams) {
    team->update();
  }

  sound.update();

  if (!startEnabled()) {
    setState(GameState::IDLE);
    resetTeams();
    return;
  }

  switch (state) {

    case GameState::IDLE:
      if (startEnabled()) {
        setState(GameState::WAIT_RANDOM_DELAY);
      }
      break;
    
    case GameState::WAIT_RANDOM_DELAY:
      detectFalseStarts();

      if (now - stateStartTime >= randomDelay) {
        sound.play(1000, SIGNAL_DURATION);
        setState(GameState::SIGNAL);
      }
      break;

    case GameState::SIGNAL:
      detectFirstAnswer();
      if (!sound.isPlaying()) {
        setState(GameState::WAIT_ANSWER);
      }
      break;

    case GameState::WAIT_ANSWER:
      detectFirstAnswer();
      break;

    case GameState::ANSWER_LOCKED:
      if (resetAnswerButton.wasPressed()) {
        teams[currentAnswerTeam]->setState(TeamState::ANSWERED);
        teams[currentAnswerTeam]->setLed(LedMode::BLINK_1HZ);

        currentAnswerTeam = -1;
        setState(GameState::WAIT_RANDOM_DELAY);
      }
      break;
  }
}

void Game::setState(GameState newState) {
  state = newState;
  stateStartTime = millis();

  if (newState == GameState::WAIT_RANDOM_DELAY) {
    randomDelay = random(RANDOM_DELAY_MIN, RANDOM_DELAY_MAX + 1);
  }
}

void Game::resetTeams() {
  for (auto &team : teams) {
    team->setState(TeamState::ACTIVE);
    team->setLed(LedMode::OFF);
  }
  currentAnswerTeam = -1;
}

void Game::detectFalseStarts() {
  for (uint8_t i = 0; i < TEAM_COUNT; ++i) {
    if (teams[i]->getState() == TeamState::ACTIVE && teams[i]->pressed()) {
      teams[i]->setState(TeamState::FALSE_START);
      teams[i]->setLed(LedMode::BLINK_1HZ);
    }
  }
}

void Game::detectFirstAnswer() {
  for (uint8_t i = 0; i < TEAM_COUNT; ++i) {
    if (teams[i]->getState() != TeamState::ACTIVE) continue;

    if (teams[i]->pressed()) {
      currentAnswerTeam = i;
      teams[i]->setLed(LedMode::ON);
      sound.play(2000, SIGNAL_DURATION);
      setState(GameState::ANSWER_LOCKED);
      break;
    }
  }
}

bool Game::startEnabled() const {
  return digitalRead(START_SWITCH_PIN) == HIGH;
}
