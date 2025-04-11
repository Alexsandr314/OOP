#include <iostream>
#include <clocale>
using namespace std;

class Array {
private:
    static const int NUMARRAYS = 10;
    static const int MAXSIZE = 10;
    int* arrays[NUMARRAYS];
public:
    Array() {
        for (int j = 0; j < NUMARRAYS; j++) {
            *(arrays + j) = new int[MAXSIZE];
        }
    }
    ~Array() {
        for (int j = 0; j < NUMARRAYS; j++) {
            delete[] * (arrays + j);
        }
    }
    int& operator[](int index) {
        if (index < 0 || index >= NUMARRAYS * MAXSIZE) {
            cout << "Ошибка: недопустимый индекс\n";
            static int dummy = 0;
            return dummy;
        }
        int arrayIndex = index / MAXSIZE;
        int elementIndex = index % MAXSIZE;
        return *(*(arrays + arrayIndex) + elementIndex);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Array a;

    // Заполнение массива
    for (int j = 0; j < 100; j++) {
        a[j] = j * 10;
    }

    // Вывод содержимого
    cout << "Содержимое объединенного массива:\n";
    for (int j = 0; j < 100; j++) {
        cout << "a[" << j << "] = " << a[j] << endl;
    }

    return 0;
}