#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream>
using namespace std;

const int NUM_FLOORS = 20; // Число этажей
const int LOAD_TIME = 3;   // Время посадки/высадки (в условных тактах)

enum direction { UP, DN, STOP }; // Направление движения

class elevator {
private:
    int current_floor;      // Текущий этаж (от 0 до NUM_FLOORS-1)
    direction current_dir;  // Текущее направление
    int loading_timer;      // Таймер посадки
    int unloading_timer;    // Таймер высадки
    bool destination;       // Флаг назначения (для одного пассажира)

public:
    elevator();             // Конструктор
    void tick();            // Один метроном для управления лифтом
    void display() const;   // Вывод состояния лифта
    void set_destination(int floor); // Установка этажа назначения
    void get_destination(); // Получение этажа назначения от пассажира
    int get_floor() const;  // Получение текущего этажа
};

#endif