#include <iostream>
#include <string>
using namespace std;

// Базовый класс publication
class publication {
protected:
    string title;
    float price;
public:
    publication() : title(""), price(0.0) {}
    publication(const string& t, float p) : title(t), price(p) {}

    virtual void getdata() {
        cout << "Введите название: ";
        cin >> title;
        cout << "Введите цену: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "Название: " << title << ", Цена: $" << price;
    }

    // Чисто виртуальная функция isOversize
    virtual bool isOversize() const = 0;

    // Виртуальный деструктор
    virtual ~publication() {}
};

// Производный класс book
class book : public publication {
private:
    int pages;
public:
    book() : pages(0) {}
    book(const string& t, float p, int pg) : publication(t, p), pages(pg) {}

    void getdata() override {
        publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    void putdata() const override {
        publication::putdata();
        cout << ", Страниц: " << pages << endl;
    }

    bool isOversize() const override {
        return pages > 800;
    }
};

// Производный класс tape
class tape : public publication {
private:
    float playtime; // Время воспроизведения в минутах
public:
    tape() : playtime(0.0) {}
    tape(const string& t, float p, float pt) : publication(t, p), playtime(pt) {}

    void getdata() override {
        publication::getdata();
        cout << "Введите время воспроизведения (в минутах): ";
        cin >> playtime;
    }

    void putdata() const override {
        publication::putdata();
        cout << ", Время: " << playtime << " минут" << endl;
    }

    bool isOversize() const override {
        return playtime > 90;
    }
};

int main() {
    publication* pubarr[100]; // Массив указателей на publication
    int n = 0; // Текущее количество объектов
    char choice;

    // Ввод данных
    do {
        cout << "Добавить книгу (b) или кассету (t)? ";
        cin >> choice;
        if (choice == 'b') {
            pubarr[n] = new book();
        }
        else if (choice == 't') {
            pubarr[n] = new tape();
        }
        else {
            cout << "Неверный выбор!\n";
            continue;
        }
        pubarr[n]->getdata();
        n++;
        cout << "Продолжить (y/n)? ";
        cin >> choice;
    } while (choice == 'y' && n < 100);

    // Вывод данных и проверка на превышение размера
    cout << "\nСписок публикаций:\n";
    for (int i = 0; i < n; i++) {
        pubarr[i]->putdata();
        if (pubarr[i]->isOversize()) {
            cout << "Превышение размера!\n";
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete pubarr[i];
    }

    return 0;
}