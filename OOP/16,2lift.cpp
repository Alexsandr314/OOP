#ifndef ELEV_H
#define ELEV_H

#include "elev_app.h"
#include "msoftcon.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <process.h>

using namespace std;

enum direction { UP, DN, STOP };
const int LOAD_TIME = 3;    // Время посадки/высадки (в тиках)
const int SPACING = 7;      // Расстояние между изображениями лифтов
const int BUF_LENGTH = 80;  // Длина буфера строки

class building; // Предварительное объявление

class elevator {
private:
    building* ptrBuilding;       // Указатель на здание
    const int car_number;        // Номер лифта (0–3)
    int current_floor;           // Текущий этаж (0–19)
    int old_floor;               // Предыдущий этаж
    direction current_dir;       // Текущее направление
    bool destination[NUM_FLOORS]; // Этажи назначения
    int loading_timer;           // Таймер посадки
    int unloading_timer;         // Таймер высадки

public:
    elevator(building* ptrB, int nc); // Конструктор
    void car_tick1();                 // Первый тик (решение и отображение)
    void car_tick2();                 // Второй тик (движение)
    void car_display();               // Отображение лифта
    void dests_display() const;       // Отображение этажей назначения
    void decide();                    // Принятие решения о движении
    void move();                      // Движение лифта
    void get_destinations();          // Получение этажей назначения
    int get_floor() const;            // Получение текущего этажа
    direction get_direction() const;   // Получение направления
};

class building {
private:
    elevator* car_list[NUM_CARS];     // Массив указателей на лифты
    int num_cars;                     // Количество созданных лифтов
    bool floor_request[2][NUM_FLOORS]; // Запросы с этажей (вверх/вниз)

public:
    building();                       // Конструктор
    ~building();                      // Деструктор
    void master_tick();               // Координация работы лифтов
    int get_cars_floor(int carNo) const; // Получение этажа лифта
    direction get_cars_dir(int carNo) const; // Получение направления лифта
    bool get_floor_req(int dir, int floor) const; // Проверка запроса с этажа
    void set_floor_req(int dir, int floor, bool value); // Установка запроса
    void record_floor_reqs();         // Ввод запросов с этажей
    void show_floor_reqs() const;     // Отображение запросов
};

#endif