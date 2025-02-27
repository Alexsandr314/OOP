#include <iostream>
#include <locale>

using namespace std;

// ��������� ��� �������� �������� ����� � ������, ��������� � ������
struct sterling {
    int pounds;     // �����
    int shillings;  // ��������
    int pence;      // �����
};

// ������� ��� ��������� ����� �� ������������
sterling getSterling() {
    sterling s;
    cout << "������� ���������� ������: ";
    cin >> s.pounds;
    cout << "������� ���������� ���������: ";
    cin >> s.shillings;
    cout << "������� ���������� ������: ";
    cin >> s.pence;
    return s;
}

// ������� ��� �������� ���� �������� ���� sterling
sterling addSterling(sterling s1, sterling s2) {
    sterling result;
    result.pence = s1.pence + s2.pence;
    result.shillings = s1.shillings + s2.shillings;
    result.pounds = s1.pounds + s2.pounds;

    // ���� ��������: 12 ������ = 1 �������, 20 ��������� = 1 ����
    if (result.pence >= 12) {
        result.shillings += result.pence / 12;
        result.pence %= 12;
    }
    if (result.shillings >= 20) {
        result.pounds += result.shillings / 20;
        result.shillings %= 20;
    }
    return result;
}

// ������� ��� ����������� ����� � ������� �����.��������.�����
void displaySterling(sterling s) {
    cout << s.pounds << "." << s.shillings << "." << s.pence;
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "������� ������ �����:" << endl;
    sterling sum1 = getSterling();

    cout << "������� ������ �����:" << endl;
    sterling sum2 = getSterling();

    // ���������� ��� �����
    sterling total = addSterling(sum1, sum2);

    cout << "\n��������� ��������: ";
    displaySterling(total);
    cout << endl;

    return 0;
}
