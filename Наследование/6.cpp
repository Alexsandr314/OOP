#include <iostream>
#include <cstdlib>  // Для exit()
#include <locale>

using namespace std;

const int SIZE = 10; // Стандартный размер массива в safearray

// Базовый класс: стандартный безопасный массив
class safearray {
protected:
    int arr[SIZE];  // Массив фиксированного размера
public:
    int& operator[](int index) {
        if (index < 0 || index >= SIZE) {
            cout << "Ошибка! Индекс " << index << " выходит за границы массива (0 - " << SIZE - 1 << ").\n";
            exit(1);
        }
        return arr[index];
    }
};

// Производный класс: массив с произвольными границами
class safehilo : public safearray {
private:
    int lower; // Нижняя граница
    int upper; // Верхняя граница
    int* dynamicArray; // Динамический массив

public:
    // Конструктор с пользовательскими границами
    safehilo(int low, int up) : lower(low), upper(up) {
        if (upper < lower) {
            cout << "Ошибка! Верхняя граница меньше нижней.\n";
            exit(1);
        }
        dynamicArray = new int[upper - lower + 1]; // Создаем массив нужного размера
    }

    // Деструктор освобождает память
    ~safehilo() {
        delete[] dynamicArray;
    }

    // Переопределенный оператор []
    int& operator[](int index) {
        if (index < lower || index > upper) {
            cout << "Ошибка! Индекс " << index << " выходит за границы массива (" << lower << " - " << upper << ").\n";
            exit(1);
        }
        return dynamicArray[index - lower]; // Преобразуем индекс в диапазоне
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Создаем массив safehilo с границами -5 до 5.\n";
    safehilo arr(-5, 5);

    // Заполняем массив значениями
    for (int i = -5; i <= 5; i++)
        arr[i] = i * 10; // Пример значений

    // Выводим значения
    cout << "Содержимое массива:\n";
    for (int i = -5; i <= 5; i++)
        cout << "arr[" << i << "] = " << arr[i] << endl;

    // Попытка выхода за границы
    cout << "\nПопробуем обратиться к arr[6]:\n";
    cout << arr[6]; // Ошибка

    return 0;
}
 