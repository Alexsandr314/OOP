#include <iostream>

using namespace std;

const int LIMIT = 100; // Фиксированный размер массива

class safearay {
private:
    int arr[LIMIT];

public:
    safearay() {
        for (int i = 0; i < LIMIT; i++)
            arr[i] = 0;
    }

    void putel(int index, int value) {
        if (index >= 0 && index < LIMIT) {
            arr[index] = value;
        }
        else {
            cout << "Ошибка: индекс " << index << " выходит за границы массива!" << endl;
        }
    }

    int getel(int index) {
        if (index >= 0 && index < LIMIT) {
            return arr[index];
        }
        else {
            cout << "Ошибка: индекс " << index << " выходит за границы массива!" << endl;
            return -1; // Возвращаем ошибочное значение
        }
    }
};

int main() {
    safearay sa1;
    int temp = 12345;

    sa1.putel(7, temp); // Запись в массив
    temp = sa1.getel(7); // Чтение из массива
    cout << "Значение по индексу 7: " << temp << endl;

    sa1.putel(150, 999); // Ошибка выхода за границы
    temp = sa1.getel(150); // Ошибка выхода за границы

    return 0;
}
