#include <iostream>
#include <cmath> // Для округления
using namespace std;

class Sterling {
private:
    long pounds;
    int shillings;
    int pence;

public:
    // Константы для пересчета
    static constexpr double PENCE_PER_POUND = 240.0; // 1 фунт = 20 шиллингов = 240 пенсов

    // 🔹 Конструкторы
    Sterling() : pounds(0), shillings(0), pence(0) {}

    // 🔹 Конструктор из double (десятичные фунты)
    Sterling(double decimalPounds) {
        long total_pence = round(decimalPounds * PENCE_PER_POUND);
        pounds = total_pence / 240;
        shillings = (total_pence % 240) / 12;
        pence = total_pence % 12;
    }

    // 🔹 Конструктор из фунтов, шиллингов и пенсов
    Sterling(long p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}

    // 🔹 Преобразование в десятичные фунты
    operator double() const {
        return pounds + (shillings * 12 + pence) / PENCE_PER_POUND;
    }

    // 🔹 Метод ввода
    void getSterling() {
        char ch;
        cout << "Введите сумму в формате £фунты.шиллинги.пенсы (например, £9.19.11): £";
        cin >> pounds >> ch >> shillings >> ch >> pence;
    }

    // 🔹 Метод вывода
    void putSterling() const {
        cout << "£" << pounds << "." << shillings << "." << pence << endl;
    }

    // 🔹 Перегрузка операций
    Sterling operator+(const Sterling& s) const {
        return Sterling(double(*this) + double(s));
    }

    Sterling operator-(const Sterling& s) const {
        return Sterling(double(*this) - double(s));
    }

    Sterling operator*(double d) const {
        return Sterling(double(*this) * d);
    }

    double operator/(const Sterling& s) const {
        return double(*this) / double(s);
    }

    Sterling operator/(double d) const {
        return Sterling(double(*this) / d);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Sterling s1, s2;
    double factor;

    // Ввод двух сумм
    s1.getSterling();
    s2.getSterling();

    cout << "Введите множитель (double): ";
    cin >> factor;

    // Выполнение операций
    Sterling sum = s1 + s2;
    Sterling diff = s1 - s2;
    Sterling prod = s1 * factor;
    double div1 = s1 / s2;
    Sterling div2 = s1 / factor;

    // Вывод результатов
    cout << "Сложение: "; sum.putSterling();
    cout << "Вычитание: "; diff.putSterling();
    cout << "Умножение: "; prod.putSterling();
    cout << "Деление (отношение двух сумм): " << div1 << endl;
    cout << "Деление на число: "; div2.putSterling();

    return 0;
}
