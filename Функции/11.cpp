#include <iostream>
#include <locale>

using namespace std;

// Структура для хранения денежной суммы в фунтах, шиллингах и пенсах
struct sterling {
    int pounds;     // Фунты
    int shillings;  // Шиллинги
    int pence;      // Пенсы
};

// Функция для получения суммы от пользователя
sterling getSterling() {
    sterling s;
    cout << "Введите количество фунтов: ";
    cin >> s.pounds;
    cout << "Введите количество шиллингов: ";
    cin >> s.shillings;
    cout << "Введите количество пенсов: ";
    cin >> s.pence;
    return s;
}

// Функция для сложения двух значений типа sterling
sterling addSterling(sterling s1, sterling s2) {
    sterling result;
    result.pence = s1.pence + s2.pence;
    result.shillings = s1.shillings + s2.shillings;
    result.pounds = s1.pounds + s2.pounds;

    // Учёт переноса: 12 пенсов = 1 шиллинг, 20 шиллингов = 1 фунт
    if (result.pence >= 12) {
        result.shillings += result.pence / 12;
        result.pence %= 12;
    }
    if (result.shillings >= 20) {
        result.pounds += result.shillings / 20;
        result.shillings %= 20;
    }
    return result;
}

// Функция для отображения суммы в формате фунты.шиллинги.пенсы
void displaySterling(sterling s) {
    cout << s.pounds << "." << s.shillings << "." << s.pence;
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Введите первую сумму:" << endl;
    sterling sum1 = getSterling();

    cout << "Введите вторую сумму:" << endl;
    sterling sum2 = getSterling();

    // Складываем две суммы
    sterling total = addSterling(sum1, sum2);

    cout << "\nРезультат сложения: ";
    displaySterling(total);
    cout << endl;

    return 0;
}
