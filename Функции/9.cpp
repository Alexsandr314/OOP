#include <iostream>
#include <locale>

using namespace std;

// ����������� ��������� �������
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// ������� ��� ������ �������
void displayTime(const Time& t) {
    cout << t.hours << " �. " << t.minutes << " ���. " << t.seconds << " ���." << endl;
}

// ������� ��� ������ �������� ���� ���������� ���� Time
void swap(Time& t1, Time& t2) {
    Time temp = t1;
    t1 = t2;
    t2 = temp;
}

int main() {
    setlocale(LC_ALL, "ru");

    // ���������� � ������������� ���� ���������� ���� Time
    Time time1 = { 2, 30, 45 };
    Time time2 = { 4, 15, 30 };

    // ����� ��������� ��������
    cout << "�� ������:" << endl;
    cout << "����� 1: ";
    displayTime(time1);
    cout << "����� 2: ";
    displayTime(time2);

    // ����� ������� swap() ��� ������ ��������
    swap(time1, time2);

    // ����� �������� ����� ������
    cout << "\n����� ������:" << endl;
    cout << "����� 1: ";
    displayTime(time1);
    cout << "����� 2: ";
    displayTime(time2);

    return 0;
}
