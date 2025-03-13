#include <iostream>

using namespace std;

const int MAX = 10; // Фиксированный размер очереди

class queue {
private:
    int arr[MAX];
    int head, tail;
    int count;

public:
    queue() : head(0), tail(-1), count(0) {}

    void put(int value) {
        if (count < MAX) {
            tail = (tail + 1) % MAX;
            arr[tail] = value;
            count++;
        }
        else {
            cout << "Ошибка: очередь переполнена!" << endl;
        }
    }

    int get() {
        if (count > 0) {
            int value = arr[head];
            head = (head + 1) % MAX;
            count--;
            return value;
        }
        else {
            cout << "Ошибка: очередь пуста!" << endl;
            return -1;
        }
    }
};

int main() {
    queue q;
    q.put(10);
    q.put(20);
    q.put(30);

    cout << "Извлечено: " << q.get() << endl;
    cout << "Извлечено: " << q.get() << endl;
    cout << "Извлечено: " << q.get() << endl;
    cout << "Извлечено: " << q.get() << endl; // Попытка извлечь из пустой очереди

    return 0;
}
