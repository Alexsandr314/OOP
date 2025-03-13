#include <iostream>

using namespace std;

const int MAX = 10; // ������������� ������ �������

class matrix {
private:
    int arr[MAX][MAX];
    int rows, cols;

public:
    matrix(int r, int c) {
        if (r > MAX || c > MAX) {
            cout << "������: �������� ���������� ������ �������!" << endl;
            exit(1);
        }
        rows = r;
        cols = c;
    }

    void putel(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            arr[row][col] = value;
        }
        else {
            cout << "������: ������ ��� ����������� ���������!" << endl;
        }
    }

    int getel(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return arr[row][col];
        }
        else {
            cout << "������: ������ ��� ����������� ���������!" << endl;
            return -1;
        }
    }
};

int main() {
    matrix m1(3, 4);
    int temp = 12345;

    m1.putel(2, 3, temp);
    cout << "��������: " << m1.getel(2, 3) << endl;

    return 0;
}

