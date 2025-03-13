#include <iostream>
#include <locale>

using namespace std;

// Структура для хранения пары чисел
struct Pair {
    int x, y;
};

// Базовый класс: стек для целых чисел
class Stack2 {
protected:
    static const int SIZE = 10;
    int stack[SIZE]; // массив для стека
    int top;         // индекс вершины

public:
    Stack2() : top(-1) {} // Конструктор

    // Добавление элемента в стек
    void push(int value) {
        if (top < SIZE - 1)
            stack[++top] = value;
        else
            cout << "Стек переполнен!" << endl;
    }

    // Извлечение элемента из стека
    int pop() {
        if (top >= 0)
            return stack[top--];
        else {
            cout << "Стек пуст!" << endl;
            return -1;
        }
    }
};

// Производный класс: стек для пар чисел
class PairStack : public Stack2 {
public:
    // Добавление пары чисел в стек
    void push(Pair p) {
        push(p.x);
        push(p.y);
    }

    // Извлечение пары чисел из стека
    Pair pop() {
        Pair p;
        p.y = pop(); // Сначала вытаскиваем y
        p.x = pop(); // Потом x
        return p;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    PairStack stack;

    // Записываем в стек три пары
    stack.push({ 1, 2 });
    stack.push({ 3, 4 });
    stack.push({ 5, 6 });

    // Извлекаем пары и выводим
    Pair p1 = stack.pop();
    cout << "Извлеченная пара: (" << p1.x << ", " << p1.y << ")" << endl;

    Pair p2 = stack.pop();
    cout << "Извлеченная пара: (" << p2.x << ", " << p2.y << ")" << endl;

    Pair p3 = stack.pop();
    cout << "Извлеченная пара: (" << p3.x << ", " << p3.y << ")" << endl;

    return 0;
}
