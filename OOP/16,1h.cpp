#ifndef HORSE_H
#define HORSE_H

#include <string>

using namespace std;

class track; // Предварительное объявление класса track

class horse {
private:
    const track* ptrTrack;      // Указатель на трассу
    const int horse_number;     // Номер лошади
    float finish_time;          // Время финиша
    float distance_run;         // Пройденная дистанция

public:
    horse(const int n, const track* ptrT); // Конструктор
    ~horse();                             // Деструктор
    void display_horse(float elapsed_time); // Отображение лошади
};

class track {
private:
    horse* hArray[7];         // Массив указателей на лошадей (максимум 7)
    int total_horses;         // Общее количество лошадей
    int horse_count;          // Текущее количество лошадей
    const float track_length; // Длина трассы
    float elapsed_time;       // Текущее время гонки

public:
    track(float lenT, int nH); // Конструктор
    ~track();                 // Деструктор
    void display_track();     // Отображение трассы
    void run();               // Запуск гонки
    float get_track_len() const; // Получение длины трассы
};

#endif