#include <iostream>
#include <cstdlib>  // Для abs() и exit()
using namespace std;

class Fraction {
private:
    int numerator, denominator;

    // Метод для нахождения наибольшего общего делителя (НОД)
    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return abs(a); // Возвращаем положительное значение
    }

public:
    // Конструктор
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cout << "Ошибка: знаменатель не может быть 0!" << endl;
            exit(1);
        }
        simplify(); // Сразу сокращаем дробь
    }

    // Метод для сокращения дроби
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
        if (denominator < 0) { // Знак храним в числителе
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Перегрузка оператора сложения
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    // Перегрузка оператора вычитания
    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    // Перегрузка оператора умножения
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Перегрузка оператора деления
    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Перегрузка оператора сравнения ==
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    // Перегрузка оператора сравнения !=
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    // Вывод дроби
    void display() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Fraction frac1, frac2, result;
    char oper;
    int num, den;

    cout << "Простой дробный калькулятор (+, -, *, /). Введите 0/1 для выхода.\n";

    while (true) {
        // Ввод первой дроби
        cout << "\nВведите первую дробь (числитель знаменатель через пробел): ";
        cin >> num >> den;
        if (num == 0 && den == 1) break; // Условие выхода
        frac1 = Fraction(num, den);

        // Ввод оператора
        cout << "Введите оператор (+, -, *, /): ";
        cin >> oper;

        // Ввод второй дроби
        cout << "Введите вторую дробь (числитель знаменатель через пробел): ";
        cin >> num >> den;
        if (num == 0 && den == 1) break; // Условие выхода
        frac2 = Fraction(num, den);

        // Вычисления
        switch (oper) {
        case '+': result = frac1 + frac2; break;
        case '-': result = frac1 - frac2; break;
        case '*': result = frac1 * frac2; break;
        case '/': result = frac1 / frac2; break;
        default:
            cout << "Ошибка: некорректный оператор!" << endl;
            continue;
        }

        // Вывод результата
        cout << "Результат: ";
        result.display();
        cout << endl;
    }

    cout << "Выход из программы.\n";
    return 0;
}
