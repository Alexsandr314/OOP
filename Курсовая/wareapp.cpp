// wareapp.cpp
// Скомпилировано: 01:45 AM +06, 31 мая 2025
#include "warehouse.h"
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    Menu menu;
    menu.showLoginMenu();

    return 0;
}