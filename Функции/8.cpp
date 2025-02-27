#include <iostream>
#include <locale>

using namespace std;

// Функция обмена значениями двух переменных типа int
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "ru");

    int x, y;
    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите значение y: ";
    cin >> y;

    cout << "\nДо обмена: x = " << x << ", y = " << y << endl;

    // Вызов функции swap
    swap(x, y);

    cout << "После обмена: x = " << x << ", y = " << y << endl;

    return 0;
}
