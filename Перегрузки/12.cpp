#include <iostream>
#include <iomanip>
#include <cmath> // Для округления
#include <string> // Для работы с денежными строками
#include <sstream> // Для конвертации строк
using namespace std;

class Sterling {
private:
    long pounds;
    int shillings;
    int pence;

public:
    static constexpr double PENCE_PER_POUND = 240.0;
    static constexpr double EXCHANGE_RATE = 50.0; // Курс: £1 = $50

    Sterling() : pounds(0), shillings(0), pence(0) {}

    Sterling(double decimalPounds) {
        long total_pence = round(decimalPounds * PENCE_PER_POUND);
        pounds = total_pence / 240;
        shillings = (total_pence % 240) / 12;
        pence = total_pence % 12;
    }

    Sterling(long p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}

    operator double() const {
        return pounds + (shillings * 12 + pence) / PENCE_PER_POUND;
    }

    void getSterling() {
        char ch;
        cout << "Введите сумму в формате £фунты.шиллинги.пенсы (например, £9.19.11): £";
        cin >> pounds >> ch >> shillings >> ch >> pence;
    }

    void putSterling() const {
        cout << "£" << pounds << "." << shillings << "." << pence;
    }
};

class bMoney {
private:
    long double amount;

public:
    static constexpr double EXCHANGE_RATE = 50.0; // Курс: £1 = $50

    bMoney() : amount(0) {}

    bMoney(long double a) : amount(a) {}

    void getMoney() {
        string moneyStr;
        cout << "Введите сумму в долларах ($1234.56): $";
        cin >> moneyStr;
        stringstream ss(moneyStr);
        ss.ignore(); // Игнорируем $
        ss >> amount;
    }

    void putMoney() const {
        cout << fixed << setprecision(2) << "$" << amount;
    }

    operator double() const {
        return amount;
    }

    // 🔹 Преобразование bMoney → Sterling
    operator Sterling() const {
        return Sterling(amount / EXCHANGE_RATE);
    }

    // 🔹 Преобразование Sterling → bMoney
    bMoney(Sterling s) {
        amount = double(s) * EXCHANGE_RATE;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Sterling s;
    bMoney m;

    int choice;
    do {
        cout << "\nВыберите операцию:\n"
            << "1. Преобразовать Sterling → bMoney\n"
            << "2. Преобразовать bMoney → Sterling\n"
            << "0. Выход\n"
            << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.getSterling();
            m = s;
            cout << "Эквивалент в долларах: ";
            m.putMoney();
            cout << endl;
            break;

        case 2:
            m.getMoney();
            s = m;
            cout << "Эквивалент в фунтах: ";
            s.putSterling();
            cout << endl;
            break;

        case 0:
            cout << "Выход из программы...\n";
            break;

        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
