#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Создание и инициализация вектора
    vector<int> vec = { 1, 2, 3, 4, 5 };

    // Вывод исходного вектора
    cout << "Original vector: ";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Переворачивание вектора с использованием прямого и обратного итераторов
    reverse(vec.begin(), vec.end());

    // Вывод перевернутого вектора
    cout << "Reversed vector: ";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}