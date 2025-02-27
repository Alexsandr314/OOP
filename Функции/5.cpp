#include <iostream>
#include <locale>

using namespace std;

// ������� �������� ������� � �������
long hms_to_secs(int hours, int minutes, int seconds) {
    return static_cast<long>(hours) * 3600 + minutes * 60 + seconds;
}

int main() {
    setlocale(LC_ALL, "ru");

    int hours, minutes, seconds;

    while (true) {
        // ���� �������
        cout << "������� ����: ";
        cin >> hours;
        cout << "������� ������: ";
        cin >> minutes;
        cout << "������� �������: ";
        cin >> seconds;

        // ����� ����������
        cout << "���������� � ��������: " << hms_to_secs(hours, minutes, seconds) << endl;

        // ���������� ��� �����
        char choice;
        cout << "����������? (�/�): ";
        cin >> choice;
        if (choice != '�' && choice != '�') break;
    }

    return 0;
}
