#include <iostream>
#include <locale>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

    // Метод для корректировки времени
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

        if (hours < 0) hours = 0; // Не позволяем отрицательное время
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Префиксный инкремент (++t)
    Time& operator++() {
        ++seconds;
        normalize();
        return *this;
    }

    // Постфиксный инкремент (t++)
    Time operator++(int) {
        Time temp = *this; // Сохраняем текущее состояние
        ++seconds;
        normalize();
        return temp; // Возвращаем старое значение
    }

    // Префиксный декремент (--t)
    Time& operator--() {
        --seconds;
        normalize();
        return *this;
    }

    // Постфиксный декремент (t--)
    Time operator--(int) {
        Time temp = *this; // Сохраняем текущее состояние
        --seconds;
        normalize();
        return temp; // Возвращаем старое значение
    }

    // Вывод времени
    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Time t1(1, 59, 59);
    cout << "Исходное время: ";
    t1.display();

    cout << "\nПрименяем префиксный ++:\n";
    ++t1;
    t1.display();

    cout << "\nПрименяем постфиксный ++:\n";
    Time t2 = t1++;
    t1.display();
    cout << "Возвращённое значение: ";
    t2.display();

    cout << "\nПрименяем префиксный --:\n";
    --t1;
    t1.display();

    cout << "\nПрименяем постфиксный --:\n";
    Time t3 = t1--;
    t1.display();
    cout << "Возвращённое значение: ";
    t3.display();

    return 0;
}
