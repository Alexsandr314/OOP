#include <iostream>
#include <iomanip>   // Для форматированного вывода
#include <string>    // Для работы со строками
#include <sstream>   // Для обработки денежной строки
#include <cstdlib>   // Для exit()
using namespace std;

class bMoney {
private:
    long double amount; // Денежная сумма

    // Преобразует строку формата "$1,234.56" в число
    long double stringToLongDouble(const string& moneyStr) {
        string numStr;
        for (char ch : moneyStr) {
            if (isdigit(ch) || ch == '.' || ch == '-') {
                numStr += ch;
            }
        }
        return stold(numStr);
    }

    // Преобразует число в строку формата "$1,234.56"
    string longDoubleToString(long double value) const {
        ostringstream oss;
        oss << fixed << setprecision(2) << value;
        string str = oss.str();

        // Добавляем запятые
        int pos = str.find('.');
        for (int i = pos - 3; i > 0; i -= 3) {
            str.insert(i, ",");
        }

        return "$" + str;
    }

public:
    // Конструкторы
    explicit bMoney(long double amt = 0.0) : amount(amt) {}
    explicit bMoney(const string& moneyStr) : amount(stringToLongDouble(moneyStr)) {}

    // Перегрузка операторов
    bMoney operator+(const bMoney& other) const {
        return bMoney(amount + other.amount);
    }

    bMoney operator-(const bMoney& other) const {
        return bMoney(amount - other.amount);
    }

    bMoney operator*(long double factor) const {
        return bMoney(amount * factor);
    }

    long double operator/(const bMoney& other) const {
        if (other.amount == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return amount / other.amount;
    }

    bMoney operator/(long double divisor) const {
        if (divisor == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return bMoney(amount / divisor);
    }

    // Вывод
    void show() const {
        cout << longDoubleToString(amount);
    }

    // Ввод
    void getMoney() {
        string moneyStr;
        cout << "Введите денежную сумму (формат: $1,234.56): ";
        cin >> moneyStr;
        amount = stringToLongDouble(moneyStr);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        bMoney b1, b2, result;
        long double num;
        char choice;

        cout << "\nВведите первую сумму:\n";
        b1.getMoney();
        cout << "Введите вторую сумму:\n";
        b2.getMoney();
        cout << "Введите число с плавающей точкой:\n";
        cin >> num;

        // Вычисления
        result = b1 + b2;
        cout << "Сумма: "; result.show(); cout << endl;

        result = b1 - b2;
        cout << "Разность: "; result.show(); cout << endl;

        result = b1 * num;
        cout << "Умножение: "; result.show(); cout << endl;

        cout << "Деление суммы 1 на сумму 2: " << b1 / b2 << endl;

        result = b1 / num;
        cout << "Деление суммы 1 на число: "; result.show(); cout << endl;

        cout << "\nХотите продолжить (y/n)? ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') break;
    }

    cout << "Выход из программы.\n";
    return 0;
}
