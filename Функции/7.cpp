#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

// ������� ���������� � ������� ��� double
double power(double base, int exp) {
    return pow(base, exp);
}

// ������������� ������� ��� float
float power(float base, int exp) {
    return pow(base, exp);
}

// ������������� ������� ��� long
long power(long base, int exp) {
    long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// ������������� ������� ��� int
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// ������������� ������� ��� char (���������� � ������� �� ���� �������)
int power(char base, int exp) {
    int baseInt = static_cast<int>(base);
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= baseInt;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    // ������� ������ ������� power() � ������� ������ ������
    char char_base = 'A'; // ��� ������� 'A' = 65
    int int_base = 2;
    long long_base = 3L;
    float float_base = 2.5f;
    double double_base = 1.5;

    int exp = 3;

    cout << "char: '" << char_base << "' � ������� " << exp << " = " << power(char_base, exp) << endl;
    cout << "int: " << int_base << " � ������� " << exp << " = " << power(int_base, exp) << endl;
    cout << "long: " << long_base << " � ������� " << exp << " = " << power(long_base, exp) << endl;
    cout << "float: " << float_base << " � ������� " << exp << " = " << power(float_base, exp) << endl;
    cout << "double: " << double_base << " � ������� " << exp << " = " << power(double_base, exp) << endl;

    return 0;
}
