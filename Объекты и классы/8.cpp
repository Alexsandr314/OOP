#include <iostream>

using namespace std;

const int LIMIT = 100; // ������������� ������ �������

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
            cout << "������: ������ " << index << " ������� �� ������� �������!" << endl;
        }
    }

    int getel(int index) {
        if (index >= 0 && index < LIMIT) {
            return arr[index];
        }
        else {
            cout << "������: ������ " << index << " ������� �� ������� �������!" << endl;
            return -1; // ���������� ��������� ��������
        }
    }
};

int main() {
    safearay sa1;
    int temp = 12345;

    sa1.putel(7, temp); // ������ � ������
    temp = sa1.getel(7); // ������ �� �������
    cout << "�������� �� ������� 7: " << temp << endl;

    sa1.putel(150, 999); // ������ ������ �� �������
    temp = sa1.getel(150); // ������ ������ �� �������

    return 0;
}
