#include <iostream>
#include <locale>

using namespace std;

int counter = 0; // Глобальная переменная для подсчета вызовов

// Функция с использованием глобальной переменной
void callCountGlobal() {
    counter++;
    cout << "Функция вызвана " << counter << " раз(а)." << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    // Вызов функции 10 раз
    for (int i = 0; i < 10; i++) {
        callCountGlobal();
    }

    return 0;
}

//#include <iostream>
//#include <locale>
//
//using namespace std;
//
//// Функция с использованием статической локальной переменной
//void callCountStatic() {
//    static int counter = 0; // Статическая переменная
//    counter++;
//    cout << "Функция вызвана " << counter << " раз(а)." << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    // Вызов функции 10 раз
//    for (int i = 0; i < 10; i++) {
//        callCountStatic();
//    }
//
//    return 0;
//}
