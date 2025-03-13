#include <iostream>
#include <cstdlib>  // Для exit()
using namespace std;

const int SIZE = 100; // Фиксированный размер массива

class safearray {
private:
    int arr[SIZE];   // Массив данных
    int lower, upper; // Нижняя и верхняя границы

public:
    // Конструктор: задает границы массива
    safearray(int low, int high) {
        if (high - low + 1 > SIZE) {
            cout << "Ошибка: превышен максимальный размер массива!" << endl;
            exit(1);
        }
        lower = low;
        upper = high;
    }

    // Перегруженный оператор []
    int& operator[](int index) {
        if (index < lower || index > upper) {
            cout << "Ошибка: выход за границы массива!" << endl;
            exit(1);
        }
        return arr[index - lower]; // Преобразование индекса
    }

    // Вывод массива (для проверки)
    void display() const {
        for (int i = 0; i <= upper - lower; i++) {
            cout << "arr[" << (i + lower) << "] = " << arr[i] << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    int low, high;
    cout << "Введите нижнюю границу индексов: ";
    cin >> low;
    cout << "Введите верхнюю границу индексов: ";
    cin >> high;

    safearray sa(low, high);

    // Заполняем массив
    for (int i = low; i <= high; i++) {
        sa[i] = i * 10; // Просто пример данных
    }

    // Выводим массив
    sa.display();

    // Тест выхода за границы (раскомментируйте для проверки)
    // cout << sa[high + 1] << endl; // Ошибка

    return 0;
}
