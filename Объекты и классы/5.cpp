#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

class fraction {
private:
    int numerator;
    int denominator;

public:
    fraction() : numerator(0), denominator(1) {}
    fraction(int num, int denom) {
        if (denom == 0) {
            cerr << "������: ����������� �� ����� ���� ����� ����!" << endl;
            exit(1);
        }
        numerator = num;
        denominator = denom;
        reduce();
    }

    void input() {
        cout << "������� ���������: ";
        cin >> numerator;
        do {
            cout << "������� ����������� (�� 0): ";
            cin >> denominator;
            if (denominator == 0) {
                cout << "������: ����������� �� ����� ���� 0! ���������� �����." << endl;
            }
        } while (denominator == 0);
        reduce();
    }

    void print() const {
        cout << numerator << "/" << denominator;
    }

    double toDecimal() const {
        return static_cast<double>(numerator) / denominator;
    }

    fraction operator+(const fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_denom = denominator * other.denominator;
        return fraction(new_num, new_denom);
    }

    fraction operator/(int count) const {
        return fraction(numerator, denominator * count);
    }

private:
    void reduce() {
        int gcd = findGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int findGCD(int a, int b) {
        return (b == 0) ? a : findGCD(b, a % b);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(nullptr));

    int n;
    cout << "������� ������ ������? ";
    cin >> n;

    vector<fraction> fractions(n);
    for (int i = 0; i < n; ++i) {
        cout << "����� " << i + 1 << ":" << endl;
        fractions[i].input();
    }

    fraction sum;
    for (const auto& f : fractions) {
        sum = sum + f;
    }

    fraction average = sum / n;
    cout << "������� ��������: ";
    average.print();
    cout << " = " << average.toDecimal() << endl;

    return 0;
}
