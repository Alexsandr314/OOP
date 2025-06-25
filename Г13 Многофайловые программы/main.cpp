#include "verylong.h"
#include <clocale>
#include <string>
#include <limits>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа для работы с длинными числами" << endl;

    string input1, input2;
    cout << "Введите первое число (например, 123 или -1234567890): ";
    cin >> input1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    cout << "Введите второе число (например, 5 или -9876543210): ";
    cin >> input2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера

    verylong a(input1.c_str());
    verylong b(input2.c_str());

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a / b = " << a / b << endl;

    return 0;
}