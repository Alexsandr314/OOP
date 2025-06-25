#ifndef VERYLONG_H
#define VERYLONG_H

#include <iostream>

const int SZ = 1000; // Максимальная длина числа в цифрах

class verylong {
private:
    char vlstr[SZ]; // Массив для хранения цифр
    int vlen;       // Длина числа
    bool isNeg;     // Флаг отрицательного числа

    // Вспомогательные функции
    void trim();                    // Удаление ведущих нулей
    void ensureCapacity(int len);   // Убеждаемся, что достаточно места

public:
    // Конструкторы
    verylong();
    verylong(const char* num);
    verylong(long n);

    // Функция сравнения
    int compare(const verylong& other) const;

    // Перегруженные операторы
    verylong operator+(const verylong& other) const;
    verylong operator-(const verylong& other) const;
    verylong operator*(const verylong& other) const; // Новый оператор умножения
    verylong operator/(const verylong& other) const;

    // Вывод числа
    friend std::ostream& operator<<(std::ostream& os, const verylong& v);
};

#endif