#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <locale>

using namespace std;

// Базовый класс сотрудника
class employee {
protected:
    string name;   // Имя сотрудника
    int number;    // Табельный номер

public:
    void getData() {
        cout << "Введите имя: ";
        getline(cin, name);
        cout << "Введите табельный номер: ";
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка ввода
    }

    void putData() const {
        cout << "Имя: " << name << "\nТабельный номер: " << number << endl;
    }
};

// Класс для компенсации (оплаты)
class compensation {
protected:
    enum PayPeriod { HOURLY, WEEKLY, MONTHLY }; // Период оплаты
    double compensationAmount; // Размер оплаты
    PayPeriod period;          // Период оплаты

public:
    void getCompensation() {
        cout << "Введите размер оплаты: ";
        cin >> compensationAmount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка ввода

        char choice;
        cout << "Выберите период оплаты (h - почасовая, w - понедельная, m - помесячная): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 'h': case 'H': period = HOURLY; break;
        case 'w': case 'W': period = WEEKLY; break;
        case 'm': case 'M': period = MONTHLY; break;
        default:
            cout << "Некорректный ввод! По умолчанию выбрана почасовая оплата.\n";
            period = HOURLY;
        }
    }

    void putCompensation() const {
        cout << "Размер оплаты: " << fixed << setprecision(2) << compensationAmount << " руб.\n"
            << "Период оплаты: " << (period == HOURLY ? "Почасовая" : (period == WEEKLY ? "Понедельная" : "Помесячная")) << "\n";
    }
};

// Новый класс employee2, который объединяет employee и compensation
class employee2 : public employee, public compensation {
public:
    void getData() {
        employee::getData();
        getCompensation();
    }

    void putData() const {
        employee::putData();
        putCompensation();
    }
};

// Классы сотрудников (менеджер, ученый, рабочий)
class manager : public employee {
protected:
    string title; // Должность

public:
    void getData() {
        employee::getData();
        cout << "Введите должность: ";
        getline(cin, title);
    }

    void putData() const {
        employee::putData();
        cout << "Должность: " << title << endl;
    }
};

class scientist : public employee {
protected:
    int publications; // Количество публикаций

public:
    void getData() {
        employee::getData();
        cout << "Введите количество публикаций: ";
        cin >> publications;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void putData() const {
        employee::putData();
        cout << "Публикации: " << publications << endl;
    }
};

class laborer : public employee {}; // Рабочий без доп. полей

// Классы с компенсацией, используя множественное наследование
class manager2 : public manager, public compensation {
public:
    void getData() {
        manager::getData();
        getCompensation();
    }

    void putData() const {
        manager::putData();
        putCompensation();
    }
};

class scientist2 : public scientist, public compensation {
public:
    void getData() {
        scientist::getData();
        getCompensation();
    }

    void putData() const {
        scientist::putData();
        putCompensation();
    }
};

class laborer2 : public laborer, public compensation {
public:
    void getData() {
        laborer::getData();
        getCompensation();
    }

    void putData() const {
        laborer::putData();
        putCompensation();
    }
};

// Главная функция
int main() {
    setlocale(LC_ALL, "ru");

    manager2 m;
    scientist2 s;
    laborer2 l;

    cout << "\nВвод данных для менеджера:\n";
    m.getData();

    cout << "\nВвод данных для ученого:\n";
    s.getData();

    cout << "\nВвод данных для рабочего:\n";
    l.getData();

    cout << "\nВывод данных:\n";
    cout << "\nМенеджер:\n"; m.putData();
    cout << "\nУченый:\n"; s.putData();
    cout << "\nРабочий:\n"; l.putData();

    return 0;
}
