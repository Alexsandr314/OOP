#include <iostream>
#include <locale>

using namespace std;

// Определение структуры времени
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Функция для вывода времени
void displayTime(const Time& t) {
    cout << t.hours << " ч. " << t.minutes << " мин. " << t.seconds << " сек." << endl;
}

// Функция для обмена значений двух переменных типа Time
void swap(Time& t1, Time& t2) {
    Time temp = t1;
    t1 = t2;
    t2 = temp;
}

int main() {
    setlocale(LC_ALL, "ru");

    // Объявление и инициализация двух переменных типа Time
    Time time1 = { 2, 30, 45 };
    Time time2 = { 4, 15, 30 };

    // Вывод начальных значений
    cout << "До обмена:" << endl;
    cout << "Время 1: ";
    displayTime(time1);
    cout << "Время 2: ";
    displayTime(time2);

    // Вызов функции swap() для обмена значений
    swap(time1, time2);

    // Вывод значений после обмена
    cout << "\nПосле обмена:" << endl;
    cout << "Время 1: ";
    displayTime(time1);
    cout << "Время 2: ";
    displayTime(time2);

    return 0;
}
