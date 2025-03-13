#include <iostream>
#include <cstring> // Для работы со строками
#include <locale>

using namespace std;

// Базовый класс Pstring (строка с безопасным размером)
class Pstring {
protected:
    static const int MAX = 100; // Максимальная длина строки
    char str[MAX]; // Буфер для строки

public:
    // Конструктор
    Pstring(const char* s = "") {
        strncpy(str, s, MAX - 1);
        str[MAX - 1] = '\0'; // Гарантия завершения строки
    }

    // Вывод строки
    void show() const {
        cout << str << endl;
    }

    // Возвращает указатель на строку
    const char* getStr() const {
        return str;
    }

    // Оператор присваивания
    Pstring& operator=(const char* s) {
        strncpy(str, s, MAX - 1);
        str[MAX - 1] = '\0';
        return *this;
    }
};

// Производный класс Pstring2 с методами left(), mid() и right()
class Pstring2 : public Pstring {
public:
    // Конструктор
    Pstring2(const char* s = "") : Pstring(s) {}

    // Копирует n левых символов из s1 в текущую строку
    Pstring2& left(const Pstring& s1, int n) {
        strncpy(str, s1.getStr(), n);
        str[n] = '\0'; // Завершаем строку
        return *this;
    }

    // Копирует n символов из середины строки, начиная с позиции s
    Pstring2& mid(const Pstring& s1, int s, int n) {
        int len = strlen(s1.getStr());
        if (s >= len) {
            str[0] = '\0'; // Если позиция вне строки, делаем строку пустой
        }
        else {
            strncpy(str, s1.getStr() + s, n);
            str[n] = '\0'; // Завершаем строку
        }
        return *this;
    }

    // Копирует n правых символов из s1 в текущую строку
    Pstring2& right(const Pstring& s1, int n) {
        int len = strlen(s1.getStr());
        if (n > len) n = len; // Если n больше длины строки, берем всю строку
        strncpy(str, s1.getStr() + (len - n), n);
        str[n] = '\0'; // Завершаем строку
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Pstring2 s1("Программирование на C++");
    Pstring2 s2;

    cout << "Исходная строка:\n";
    s1.show();

    cout << "\nЛевые 12 символов:\n";
    s2.left(s1, 12).show();

    cout << "\nСредние 11 символов (с 14-й позиции):\n";
    s2.mid(s1, 14, 11).show();

    cout << "\nПравые 5 символов:\n";
    s2.right(s1, 5).show();

    return 0;
}
