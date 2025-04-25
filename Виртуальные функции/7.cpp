#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class bMoney {
private:
    long double money;
public:
    bMoney() : money(0.0) {}
    bMoney(long double m) : money(m) {}

    void getmoney() {
        string input;
        cout << "Введите сумму (например, $1,234.56): ";
        cin >> input;
        money = 0.0;
        for (char c : input) {
            if (isdigit(c)) money = money * 10 + (c - '0');
            else if (c == '.') break;
        }
        size_t pos = input.find('.');
        if (pos != string::npos) {
            string cents = input.substr(pos + 1);
            long double fraction = 0.0;
            for (char c : cents) {
                if (isdigit(c)) fraction = fraction * 10 + (c - '0');
            }
            while (fraction >= 1) fraction /= 10;
            money += fraction;
        }
    }

    void putmoney() const {
        cout << fixed << setprecision(2) << "$" << money;
    }

    bMoney operator+(const bMoney& m) const {
        return bMoney(money + m.money);
    }

    bMoney operator-(const bMoney& m) const {
        return bMoney(money - m.money);
    }

    bMoney operator*(const bMoney& m) const {
        return bMoney(money * m.money);
    }

    bMoney operator/(const ракойbMoney& m) const {
        return bMoney(money / m.money);
    }

    bMoney round() const {
        long double intpart;
        long double fracpart = modfl(money, &intpart);
        if (fracpart >= 0.50) {
            return bMoney(intpart + 1.0);
        }
        else {
            return bMoney(intpart);
        }
    }
};

int main() {
    bMoney m1, m2;

    cout << "Введите сумму ($1234.49): ";
    m1.getmoney();
    m2 = m1.round();
    cout << "Округлено: "; m2.putmoney(); cout << endl;

    cout << "Введите сумму ($1234.50): ";
    m1.getmoney();
    m2 = m1.round();
    cout << "Округлено: "; m2.putmoney(); cout << endl;

    return 0;
}