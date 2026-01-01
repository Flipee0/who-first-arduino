#pragma once
#include <Arduino.h>

constexpr uint8_t TEAM_COUNT = 20;

constexpr uint8_t teamLedPins[TEAM_COUNT]   = { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33 };
constexpr uint8_t teamButtonPins[TEAM_COUNT] = { 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53 };

constexpr uint8_t START_SWITCH_PIN = 13;
constexpr uint8_t RESET_ANSWER_PIN   = 12;
constexpr uint8_t SOUND_PIN   = 11; 

constexpr uint32_t RANDOM_DELAY_MIN = 1000;
constexpr uint32_t RANDOM_DELAY_MAX = 3000;

constexpr uint32_t SIGNAL_DURATION  = 2000;
constexpr uint32_t BLINK_INTERVAL   = 500;
