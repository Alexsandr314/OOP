#include <iostream>
#include <locale>

using namespace std;

// Базовый класс: фунты-стерлинги-пенсы
class sterling {
protected:
    int pounds, shillings, pence;

public:
    // Конструктор по умолчанию
    sterling() : pounds(0), shillings(0), pence(0) {}

    // Конструктор с параметрами
    sterling(int p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}

    // Метод для ввода данных
    void set() {
        cout << "Введите сумму в формате £Ф.Ш.П (Фунты.Шиллинги.Пенсы): ";
        char ch;
        cin >> pounds >> ch >> shillings >> ch >> pence;
    }

    // Метод для вывода данных
    void show() const {
        cout << "£" << pounds << "." << shillings << "." << pence;
    }
};

// Производный класс: с дробными частями пенни
class sterfrac : public sterling {
private:
    int eighths; // Восьмые доли пенни

public:
    // Конструктор по умолчанию
    sterfrac() : sterling(), eighths(0) {}

    // Конструктор с параметрами
    sterfrac(int p, int s, int pe, int e) : sterling(p, s, pe), eighths(e) {}

    // Метод для ввода суммы с дробными частями пенни
    void set() {
        sterling::set();
        cout << "Введите дробные части пенни (0, 1/8, 1/4, ... 7/8): ";
        char ch;
        cin >> eighths >> ch;
    }

    // Метод для вывода суммы
    void show() const {
        sterling::show();
        cout << "-" << eighths << "/8";
    }

    // Операция сложения
    sterfrac operator+(const sterfrac& other) const {
        int total_eighths = (pence * 8 + eighths) + (other.pence * 8 + other.eighths);
        int new_pence = total_eighths / 8;
        int new_eighths = total_eighths % 8;
        return sterfrac(pounds + other.pounds, shillings + other.shillings, new_pence, new_eighths);
    }

    // Операция вычитания
    sterfrac operator-(const sterfrac& other) const {
        int total_eighths = (pence * 8 + eighths) - (other.pence * 8 + other.eighths);
        int new_pence = total_eighths / 8;
        int new_eighths = total_eighths % 8;
        return sterfrac(pounds - other.pounds, shillings - other.shillings, new_pence, new_eighths);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    sterfrac s1, s2, result;

    cout << "Введите первую сумму:\n";
    s1.set();

    cout << "Введите вторую сумму:\n";
    s2.set();

    // Сложение
    result = s1 + s2;
    cout << "Результат сложения: ";
    result.show();
    cout << endl;

    // Вычитание
    result = s1 - s2;
    cout << "Результат вычитания: ";
    result.show();
    cout << endl;

    return 0;
}
