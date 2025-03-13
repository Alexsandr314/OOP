#include <iostream>
#include <string>
#include <locale>

using namespace std;

// Класс для хранения даты
class Date {
private:
    int day, month, year;
public:
    // Конструктор по умолчанию
    Date() : day(1), month(1), year(2000) {}

    // Конструктор с параметрами
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Ввод даты
    void input() {
        cout << "Введите день: ";
        cin >> day;
        cout << "Введите месяц: ";
        cin >> month;
        cout << "Введите год: ";
        cin >> year;
    }

    // Вывод даты
    void display() const {
        cout << day << "." << month << "." << year;
    }
};

// Базовый класс "Публикация"
class Publication {
protected:
    string title;
    float price;
public:
    // Конструктор по умолчанию
    Publication() : title(""), price(0.0) {}

    // Ввод данных
    void getData() {
        cout << "Введите название: ";
        cin.ignore();
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    // Вывод данных
    void putData() const {
        cout << "Название: " << title << "\nЦена: " << price << " сом\n";
    }
};

// Новый класс "Публикация 2" (расширяет Publication, добавляя дату)
class Publication2 : public Publication {
protected:
    Date releaseDate;
public:
    // Ввод данных
    void getData() {
        Publication::getData();
        cout << "Введите дату выхода книги:\n";
        releaseDate.input();
    }

    // Вывод данных
    void putData() const {
        Publication::putData();
        cout << "Дата выхода: ";
        releaseDate.display();
        cout << endl;
    }
};

// Класс "Книга" (наследуется от Publication2)
class Book : public Publication2 {
private:
    int pages;
public:
    // Ввод данных
    void getData() {
        Publication2::getData();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    // Вывод данных
    void putData() const {
        Publication2::putData();
        cout << "Страниц: " << pages << endl;
    }
};

// Класс "Тип публикации" (например, аудиокнига, статья и т. д.)
class Type : public Publication2 {
private:
    float duration; // Продолжительность в минутах
public:
    // Ввод данных
    void getData() {
        Publication2::getData();
        cout << "Введите продолжительность (в минутах): ";
        cin >> duration;
    }

    // Вывод данных
    void putData() const {
        Publication2::putData();
        cout << "Продолжительность: " << duration << " мин\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Book b;
    Type t;

    cout << "Введите данные для книги:\n";
    b.getData();

    cout << "\nВведите данные для типа публикации (например, аудиокнига):\n";
    t.getData();

    cout << "\nИнформация о книге:\n";
    b.putData();

    cout << "\nИнформация о типе публикации:\n";
    t.putData();

    return 0;
}
