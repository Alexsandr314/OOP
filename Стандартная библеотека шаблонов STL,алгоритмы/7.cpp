#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Создание и инициализация вектора
    vector<double> fares = { 100.50, 200.75, 150.25, 300.00 };

    // Вычисление суммы с использованием accumulate с тремя аргументами
    double total = accumulate(fares.begin(), fares.end(), 0.0);

    // Вывод результата
    cout << "Total fares: " << total << endl;

    return 0;
}