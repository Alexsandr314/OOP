#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

// Функция возведения в степень для double
double power(double base, int exp) {
    return pow(base, exp);
}

// Перегруженная функция для float
float power(float base, int exp) {
    return pow(base, exp);
}

// Перегруженная функция для long
long power(long base, int exp) {
    long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// Перегруженная функция для int
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// Перегруженная функция для char (возведение в степень по коду символа)
int power(char base, int exp) {
    int baseInt = static_cast<int>(base);
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= baseInt;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    // Примеры вызова функции power() с разными типами данных
    char char_base = 'A'; // Код символа 'A' = 65
    int int_base = 2;
    long long_base = 3L;
    float float_base = 2.5f;
    double double_base = 1.5;

    int exp = 3;

    cout << "char: '" << char_base << "' в степени " << exp << " = " << power(char_base, exp) << endl;
    cout << "int: " << int_base << " в степени " << exp << " = " << power(int_base, exp) << endl;
    cout << "long: " << long_base << " в степени " << exp << " = " << power(long_base, exp) << endl;
    cout << "float: " << float_base << " в степени " << exp << " = " << power(float_base, exp) << endl;
    cout << "double: " << double_base << " в степени " << exp << " = " << power(double_base, exp) << endl;

    return 0;
}
