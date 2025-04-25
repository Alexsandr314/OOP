#include <iostream>
using namespace std;

class link {
public:
    double data;
    link* next;
    link(double d) : data(d), next(nullptr) {}
};

class linklist {
private:
    link* first;
public:
    linklist() : first(nullptr) {}

    // Конструктор копирования
    linklist(const linklist& other) : first(nullptr) {
        link* current = other.first;
        link* last = nullptr;
        while (current) {
            link* newlink = new link(current->data);
            if (!first) {
                first = newlink;
            }
            else {
                last->next = newlink;
            }
            last = newlink;
            current = current->next;
        }
    }

    void additem(double d) {
        link* newlink = new link(d);
        newlink->next = first;
        first = newlink;
    }

    void display() const {
        link* current = first;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Перегрузка оператора присваивания
    linklist& operator=(const linklist& other) {
        if (this == &other) return *this;

        // Очистка текущего списка
        while (first) {
            link* temp = first;
            first = first->next;
            delete temp;
        }

        // Копирование элементов
        link* current = other.first;
        link* last = nullptr;
        while (current) {
            link* newlink = new link(current->data);
            if (!first) {
                first = newlink;
            }
            else {
                last->next = newlink;
            }
            last = newlink;
            current = current->next;
        }

        return *this;
    }

    // Деструктор
    ~linklist() {
        while (first) {
            link* temp = first;
            first = first->next;
            delete temp;
        }
    }
};

int main() {
    linklist* list1 = new linklist();
    list1->additem(1.5);
    list1->additem(2.7);
    list1->additem(3.2);

    cout << "Список 1: ";
    list1->display();

    linklist* list2 = new linklist();
    *list2 = *list1;

    cout << "Список 2 (после присваивания): ";
    list2->display();

    delete list1;
    cout << "Список 2 (после удаления list1): ";
    list2->display();

    delete list2;
    return 0;
}