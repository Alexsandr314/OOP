#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

setlocale(LC_ALL, "ru"); // Русификатор

// Структура для дробей
struct fraction {
    int numerator;
    int denominator;
};

// Функция для нахождения НОД
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Функция для сокращения дроби
fraction reduce(fraction frac) {
    int divisor = gcd(abs(frac.numerator), abs(frac.denominator));
    frac.numerator /= divisor;
    frac.denominator /= divisor;
    if (frac.denominator < 0) { // Если знаменатель отрицательный
        frac.numerator *= -1;
        frac.denominator *= -1;
    }
    return frac;
}

// Сложение
fraction fadd(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return reduce(result);
}

// Вычитание
fraction fsub(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return reduce(result);
}

// Умножение
fraction fmul(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return reduce(result);
}

// Деление
fraction fdiv(fraction f1, fraction f2) {
    if (f2.numerator == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        exit(1);
    }
    fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    return reduce(result);
}

// Вывод дроби
void printFraction(const fraction& frac) {
    cout << frac.numerator << "/" << frac.denominator;
}

// Ввод дроби
fraction inputFraction() {
    fraction frac;
    cout << "Введите числитель: ";
    cin >> frac.numerator;
    cout << "Введите знаменатель: ";
    cin >> frac.denominator;
    if (frac.denominator == 0) {
        cout << "Ошибка: знаменатель не может быть нулём!" << endl;
        exit(1);
    }
    return frac;
}

int main() {
    fraction f1, f2;
    cout << "Введите первую дробь:" << endl;
    f1 = inputFraction();
    cout << "Введите вторую дробь:" << endl;
    f2 = inputFraction();

    cout << "\nРезультаты операций:" << endl;

    cout << "Сложение: ";
    printFraction(fadd(f1, f2));
    cout << endl;

    cout << "Вычитание: ";
    printFraction(fsub(f1, f2));
    cout << endl;

    cout << "Умножение: ";
    printFraction(fmul(f1, f2));
    cout << endl;

    cout << "Деление: ";
    printFraction(fdiv(f1, f2));
    cout << endl;

    return 0;
}
