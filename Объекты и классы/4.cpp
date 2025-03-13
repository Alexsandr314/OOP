#include <iostream>
#include <locale>

using namespace std;

// ����� ��� ������ � ��������
class IntArray {
private:
    int* arr;  // ��������� �� ������
    int size;  // ������ �������
public:
    // �����������
    IntArray(int s) : size(s) {
        arr = new int[size];
    }

    // ����������
    ~IntArray() {
        delete[] arr;
    }

    // ����� ��� ����� ���������
    void input() {
        cout << "������� " << size << " ����� �����: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // ����� ��� ������ ������� ����������� ��������
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

    // ����� ��� ��������� �������� �������� �� �������
    int getValue(int index) const {
        return arr[index];
    }
};

int main() {
    setlocale(LC_ALL, "ru"); // ������������� ������� ����

    int size;
    cout << "������� ���������� ��������� �������: ";
    cin >> size;

    if (size <= 0) {
        cout << "������ ������� ������ ���� �������������." << endl;
        return 1;
    }

    IntArray arr(size); // �������� ������� �������
    arr.input(); // ���� ��������

    int maxIdx = arr.maxIndex(); // ����� ������� ������������� ��������

    if (maxIdx != -1) {
        cout << "���������� �������: " << arr.getValue(maxIdx) << endl;
        cout << "������ ����������� ��������: " << maxIdx << endl;
    }
    else {
        cout << "������ ��� ������ ������������� ��������." << endl;
    }

    return 0;
}
