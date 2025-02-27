#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

setlocale(LC_ALL, "ru"); // �����������

// ��������� ��� ������
struct fraction {
    int numerator;
    int denominator;
};

// ������� ��� ���������� ���
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// ������� ��� ���������� �����
fraction reduce(fraction frac) {
    int divisor = gcd(abs(frac.numerator), abs(frac.denominator));
    frac.numerator /= divisor;
    frac.denominator /= divisor;
    if (frac.denominator < 0) { // ���� ����������� �������������
        frac.numerator *= -1;
        frac.denominator *= -1;
    }
    return frac;
}

// ��������
fraction fadd(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return reduce(result);
}

// ���������
fraction fsub(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return reduce(result);
}

// ���������
fraction fmul(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return reduce(result);
}

// �������
fraction fdiv(fraction f1, fraction f2) {
    if (f2.numerator == 0) {
        cout << "������: ������� �� ����!" << endl;
        exit(1);
    }
    fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    return reduce(result);
}

// ����� �����
void printFraction(const fraction& frac) {
    cout << frac.numerator << "/" << frac.denominator;
}

// ���� �����
fraction inputFraction() {
    fraction frac;
    cout << "������� ���������: ";
    cin >> frac.numerator;
    cout << "������� �����������: ";
    cin >> frac.denominator;
    if (frac.denominator == 0) {
        cout << "������: ����������� �� ����� ���� ����!" << endl;
        exit(1);
    }
    return frac;
}

int main() {
    fraction f1, f2;
    cout << "������� ������ �����:" << endl;
    f1 = inputFraction();
    cout << "������� ������ �����:" << endl;
    f2 = inputFraction();

    cout << "\n���������� ��������:" << endl;

    cout << "��������: ";
    printFraction(fadd(f1, f2));
    cout << endl;

    cout << "���������: ";
    printFraction(fsub(f1, f2));
    cout << endl;

    cout << "���������: ";
    printFraction(fmul(f1, f2));
    cout << endl;

    cout << "�������: ";
    printFraction(fdiv(f1, f2));
    cout << endl;

    return 0;
}
