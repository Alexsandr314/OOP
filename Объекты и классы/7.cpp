#include <iostream>
#include <string>
#include <cctype>
#include <clocale>

using namespace std;

class money {
private:
    long double amount;

public:
    money() : amount(0.0) {}

    void mstold(const string& moneyStr) {
        string numStr;
        for (char ch : moneyStr) {
            if (isdigit(ch) || ch == '.') {
                numStr += ch;
            }
        }
        amount = stold(numStr);
    }

    void show() const {
        cout << "����� � �������� �������: " << amount << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    money m;
    string input;

    while (true) {
        cout << "������� �������� �������� (��������, $1,234,567,890.99) ��� 'exit' ��� ������: ";
        cin >> input;

        if (input == "exit") break;

        m.mstold(input);
        m.show();
    }

    return 0;
}
