#include <iostream>
#include <locale>

using namespace std;

// Класс для работы с массивом
class IntArray {
private:
    int* arr;  // Указатель на массив
    int size;  // Размер массива
public:
    // Конструктор
    IntArray(int s) : size(s) {
        arr = new int[size];
    }

    // Деструктор
    ~IntArray() {
        delete[] arr;
    }

    // Метод для ввода элементов
    void input() {
        cout << "Введите " << size << " целых чисел: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Метод для поиска индекса наибольшего элемента
    int maxIndex() const {
        if (size <= 0) return -1;

        int maxIdx = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    // Метод для получения значения элемента по индексу
    int getValue(int index) const {
        return arr[index];
    }
};

int main() {
    setlocale(LC_ALL, "ru"); // Устанавливаем русский язык

    int size;
    cout << "Введите количество элементов массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Размер массива должен быть положительным." << endl;
        return 1;
    }

    IntArray arr(size); // Создание объекта массива
    arr.input(); // Ввод значений

    int maxIdx = arr.maxIndex(); // Поиск индекса максимального элемента

    if (maxIdx != -1) {
        cout << "Наибольший элемент: " << arr.getValue(maxIdx) << endl;
        cout << "Индекс наибольшего элемента: " << maxIdx << endl;
    }
    else {
        cout << "Ошибка при поиске максимального элемента." << endl;
    }

    return 0;
}
