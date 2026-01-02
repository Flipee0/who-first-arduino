#pragma once
#include <Arduino.h>

// НАСТРОЙКИ ПИНОВ
constexpr uint8_t TEAM_COUNT = 20; // кол-во команд, должно быть = кол-ву элементов в массивах ниже

constexpr uint8_t teamLedPins[TEAM_COUNT]   = { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33 }; // лампы команд
constexpr uint8_t teamButtonPins[TEAM_COUNT] = { 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53 }; // кнопки команд, 1 к 1 по индексам с лампами

constexpr uint8_t START_SWITCH_PIN = 13; // переключатель для старта
constexpr uint8_t RESET_ANSWER_PIN = 12; // кнопка сброса ответа
constexpr uint8_t SOUND_PIN = 11; // динамик
constexpr uint8_t GARLAND_GAME_SWITCH_PIN = 10; // переключатель игра <-> гирлянда 


// НАСТРОЙКИ ИГРЫ
constexpr uint32_t RANDOM_DELAY_MIN = 1000; // нижний порог задержки перед ответом (мс)
constexpr uint32_t RANDOM_DELAY_MAX = 3000; // верхний порог задержки перед ответом (мс)

constexpr uint32_t SIGNAL_DURATION  = 2000; // длительность звукового сигнала (мс)
constexpr uint32_t BLINK_INTERVAL   = 500; // интервал переключения сигнала при мигрании лампы (мс), равняется частоте / 2


// НАСТРОЙКИ ГИРЛЯНДЫ
constexpr uint32_t GARLAND_MODE_DURATION = 3000; // длительность режима (мс)
constexpr uint32_t GARLAND_TOTAL_COLORS = 6; // кол-во цветов

enum GarlandMode {
  RUN_FORWARD,
  RUN_BACKWARD,
  BLINK,
  RUN_COLORS
};

constexpr uint32_t GARLAND_MODES_COUNT = 4; // кол-во режимов гирлянды
constexpr GarlandMode garlandAllModes[GARLAND_MODES_COUNT] = { 
  GarlandMode::RUN_FORWARD, GarlandMode::RUN_BACKWARD, GarlandMode::BLINK, GarlandMode::RUN_COLORS
}; // последовательность режимов гирлянды, кол-во элементов = GARLAND_MODES_COUNT

constexpr uint32_t BLINKS_COUNT = 6; // кол-во переключений в режиме мигания
