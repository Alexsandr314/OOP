#include <iostream>
#include <locale>

using namespace std;

// Базовый класс счетчика (COUNTEN2)
class Counter {
protected:
    int count; // Значение счетчика
public:
    // Конструктор
    Counter(int c = 0) : count(c) {}

    // Префиксный инкремент (++counter)
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Префиксный декремент (--counter)
    Counter& operator--() {
        --count;
        return *this;
    }

    // Вывод значения
    void show() const {
        cout << "Значение счетчика: " << count << endl;
    }
};

// Производный класс с постфиксными операциями
class CounterPostfix : public Counter {
public:
    // Используем конструктор базового класса
    CounterPostfix(int c = 0) : Counter(c) {}

    // Постфиксный инкремент (counter++)
    CounterPostfix operator++(int) {
        CounterPostfix temp = *this; // Сохраняем старое значение
        count++; // Увеличиваем значение
        return temp; // Возвращаем старый объект
    }

    // Постфиксный декремент (counter--)
    CounterPostfix operator--(int) {
        CounterPostfix temp = *this; // Сохраняем старое значение
        count--; // Уменьшаем значение
        return temp; // Возвращаем старый объект
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    CounterPostfix c(5);
    cout << "Исходное значение:\n";
    c.show();

    cout << "\nПрефиксный инкремент (++c):\n";
    ++c;
    c.show();

    cout << "\nПостфиксный инкремент (c++):\n";
    c++;
    c.show();

    cout << "\nПрефиксный декремент (--c):\n";
    --c;
    c.show();

    cout << "\nПостфиксный декремент (c--):\n";
    c--;
    c.show();

    return 0;
}
