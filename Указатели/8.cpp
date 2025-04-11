#include <iostream>
#include <clocale>
using namespace std;

struct link {
    int data;
    link* next;
};

class linklist {
private:
    link* first;
public:
    linklist() {
        first = nullptr;
    }
    ~linklist() {
        link* current = first;
        while (current != nullptr) {
            link* temp = current;
            current = current->next;
            cout << "Удален элемент с данными: " << temp->data << endl;
            delete temp;
        }
    }
    void additem(int d) {
        link* newlink = new link;
        newlink->data = d;
        newlink->next = nullptr;
        if (first == nullptr) {
            first = newlink;
        }
        else {
            link* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newlink;
        }
    }
    void display() {
        link* current = first;
        cout << "Список элементов:\n";
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    linklist li;
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display();

    return 0;
}