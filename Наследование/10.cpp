#include <iostream>
#include <string>
#include <locale>

using namespace std;

// Базовый класс "Служащий"
class Employee {
protected:
    string name;
    long id;
public:
    // Конструктор по умолчанию
    Employee() : name(""), id(0) {}

    // Ввод данных
    void getData() {
        cout << "Введите имя: ";
        cin.ignore();
        getline(cin, name);
        cout << "Введите ID: ";
        cin >> id;
    }

    // Вывод данных
    void putData() const {
        cout << "Имя: " << name << "\nID: " << id << endl;
    }
};

// Производный класс "Менеджер"
class Manager : public Employee {
protected:
    string department;
public:
    // Ввод данных
    void getData() {
        Employee::getData();
        cout << "Введите отдел: ";
        cin.ignore();
        getline(cin, department);
    }

    // Вывод данных
    void putData() const {
        Employee::putData();
        cout << "Отдел: " << department << endl;
    }
};

// Производный класс "Управляющий" (главный менеджер)
class Executive : public Manager {
private:
    double bonus;  // Годовая премия
    int shares;    // Количество акций
public:
    // Ввод данных
    void getData() {
        Manager::getData();
        cout << "Введите годовую премию ($): ";
        cin >> bonus;
        cout << "Введите количество акций: ";
        cin >> shares;
    }

    // Вывод данных
    void putData() const {
        Manager::putData();
        cout << "Годовая премия: $" << bonus << "\nАкции: " << shares << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Executive exec;

    cout << "Введите данные для управляющего:\n";
    exec.getData();

    cout << "\nИнформация об управляющем:\n";
    exec.putData();

    return 0;
}
