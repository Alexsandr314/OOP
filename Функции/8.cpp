#include <iostream>
#include <locale>

using namespace std;

// ������� ������ ���������� ���� ���������� ���� int
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "ru");

    int x, y;
    cout << "������� �������� x: ";
    cin >> x;
    cout << "������� �������� y: ";
    cin >> y;

    cout << "\n�� ������: x = " << x << ", y = " << y << endl;

    // ����� ������� swap
    swap(x, y);

    cout << "����� ������: x = " << x << ", y = " << y << endl;

    return 0;
}
