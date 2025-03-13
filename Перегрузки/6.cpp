#include <iostream>
#include <locale>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

    // Приватный метод для нормализации времени
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        else if (seconds < 0) {
            minutes -= (abs(seconds) + 59) / 60;
            seconds = (seconds % 60 + 60) % 60;
        }

        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        else if (minutes < 0) {
            hours -= (abs(minutes) + 59) / 60;
            minutes = (minutes % 60 + 60) % 60;
        }

        if (hours < 0) hours = 0; // Не допускаем отрицательное время
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Перегрузка оператора вычитания (-) для разности двух объектов Time
    Time operator-(const Time& other) const {
        int totalSec1 = hours * 3600 + minutes * 60 + seconds;
        int totalSec2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int diff = totalSec1 - totalSec2;

        if (diff < 0) diff = 0; // Предотвращаем отрицательное время

        return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    // Перегрузка оператора умножения (float * Time)
    Time operator*(float multiplier) const {
        int totalSec = (hours * 3600 + minutes * 60 + seconds) * multiplier;
        return Time(totalSec / 3600, (totalSec % 3600) / 60, totalSec % 60);
    }

    // Вывод времени в формате HH:MM:SS
    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Time t1(2, 45, 30);
    Time t2(1, 20, 15);

    cout << "Время 1: ";
    t1.display();
    cout << "Время 2: ";
    t2.display();

    // Вычитание времени
    Time diff = t1 - t2;
    cout << "\nРазница (t1 - t2): ";
    diff.display();

    // Умножение времени на float
    float factor = 1.5;
    Time multiplied = t1 * factor;
    cout << "\nУмноженное время (t1 * " << factor << "): ";
    multiplied.display();

    return 0;
}
