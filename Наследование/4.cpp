#include <iostream>
#include <string>
#include <iomanip>  // для форматированного вывода
#include <limits>   // для очистки ввода
#include <locale>   // для русификации

using namespace std;

class publication {
protected:
    string title;  // Название публикации
    float price;   // Цена публикации

public:
    void getData() {
        cout << "Введите название публикации: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очистка ввода
    }

    void putData() const {
        cout << "Название: " << title << "\nЦена: " << fixed << setprecision(2) << price << " руб.\n";
    }
};

// Новый производный класс
class disk : public publication {
private:
    enum DiskType { CD, DVD };  // Перечисление для типа диска
    DiskType diskType;          // Поле для хранения типа

public:
    void getData() {
        publication::getData();  // Вызов метода базового класса

        char choice;
        cout << "Выберите тип диска (c - CD, d - DVD): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очистка ввода

        if (choice == 'c' || choice == 'C')
            diskType = CD;
        else if (choice == 'd' || choice == 'D')
            diskType = DVD;
        else {
            cout << "Некорректный ввод! По умолчанию выбран CD.\n";
            diskType = CD;
        }
    }

    void putData() const {
        publication::putData();  // Вызов метода базового класса

        cout << "Тип диска: " << (diskType == CD ? "CD" : "DVD") << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    disk myDisk;
    myDisk.getData();
    cout << "\nДанные о диске:\n";
    myDisk.putData();

    return 0;
}
