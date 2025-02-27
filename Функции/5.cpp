#include <iostream>
#include <locale>

using namespace std;

// Функция перевода времени в секунды
long hms_to_secs(int hours, int minutes, int seconds) {
    return static_cast<long>(hours) * 3600 + minutes * 60 + seconds;
}

int main() {
    setlocale(LC_ALL, "ru");

    int hours, minutes, seconds;

    while (true) {
        // Ввод времени
        cout << "Введите часы: ";
        cin >> hours;
        cout << "Введите минуты: ";
        cin >> minutes;
        cout << "Введите секунды: ";
        cin >> seconds;

        // Вывод результата
        cout << "Эквивалент в секундах: " << hms_to_secs(hours, minutes, seconds) << endl;

        // Продолжить или выйти
        char choice;
        cout << "Продолжить? (д/н): ";
        cin >> choice;
        if (choice != 'д' && choice != 'Д') break;
    }

    return 0;
}
