#include <iostream>

using namespace std;

const int MAX = 10; // ������������� ������ �������

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
            cout << "������: ������� �����������!" << endl;
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
            cout << "������: ������� �����!" << endl;
            return -1;
        }
    }
};

int main() {
    queue q;
    q.put(10);
    q.put(20);
    q.put(30);

    cout << "���������: " << q.get() << endl;
    cout << "���������: " << q.get() << endl;
    cout << "���������: " << q.get() << endl;
    cout << "���������: " << q.get() << endl; // ������� ������� �� ������ �������

    return 0;
}
