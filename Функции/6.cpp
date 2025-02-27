#include <iostream>
#include <locale>

using namespace std;

// ��������� ��� �������� �������
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// ������� �������� ������� � �������
long time_to_secs(Time t) {
    return static_cast<long>(t.hours) * 3600 + t.minutes * 60 + t.seconds;
}

// ������� �������� ������ � ��������� �������
Time secs_to_time(long total_seconds) {
    Time t;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600;
    t.minutes = total_seconds / 60;
    t.seconds = total_seconds % 60;
    return t;
}

int main() {
    setlocale(LC_ALL, "ru");

    Time t1, t2, sum;
    long total_seconds;

    // ���� ������� �������
    cout << "������� ������ �����:" << endl;
    cout << "����: ";
    cin >> t1.hours;
    cout << "������: ";
    cin >> t1.minutes;
    cout << "�������: ";
    cin >> t1.seconds;

    // ���� ������� �������
    cout << "������� ������ �����:" << endl;
    cout << "����: ";
    cin >> t2.hours;
    cout << "������: ";
    cin >> t2.minutes;
    cout << "�������: ";
    cin >> t2.seconds;

    // �������� ������� � ��������
    total_seconds = time_to_secs(t1) + time_to_secs(t2);

    // ������� � ��������� �������
    sum = secs_to_time(total_seconds);

    // ����� ����������
    cout << "����� �������: " << sum.hours << " �����, "
        << sum.minutes << " �����, " << sum.seconds << " ������." << endl;

    return 0;
}