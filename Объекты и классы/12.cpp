#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX = 10; // Фиксированный размер матрицы

class bMoney {
private:
    long double money;

    long double mstold(const string& str) {
        string num_str;
        for (char ch : str) {
            if ((ch >= '0' && ch <= '9') || ch == '.') {
                num_str += ch;
            }
        }
        return stold(num_str);
    }

    string ldtoms(long double value) {
        if (value > 9'999'999'999'999'990.00) {
            return "$Overflow";
        }
        stringstream ss;
        ss << fixed << setprecision(2) << value;
        string num_str = ss.str();

        int pos = num_str.find('.');
        int start = (pos == string::npos) ? num_str.size() : pos;
        string result = "$";
        int count = 0;

        for (int i = start - 1; i >= 0; --i) {
            if (count == 3) {
                result = "," + result;
                count = 0;
            }
            result = num_str[i] + result;
            count++;
        }

        result += num_str.substr(start);
        return result;
    }

public:
    bMoney() : money(0.0) {}

    bMoney(const char s[]) {
        money = mstold(s);
    }

    void madd(bMoney m1, bMoney m2) {
        money = m1.money + m2.money;
    }

    void getmoney() {
        string input;
        cout << "Введите денежное значение: ";
        cin >> input;
        money = mstold(input);
    }

    void putmoney() {
        cout << "Денежное значение: " << ldtoms(money) << endl;
    }
};

int main() {
    bMoney m1, m2, m3;
    m1.getmoney();
    m2.getmoney();
    m3.madd(m1, m2);
    m3.putmoney();
    return 0;
}
