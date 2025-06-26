#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Создание и инициализация вектора
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Ввод позиций
    int first1, last1, first2;
    cout << "Enter first1, last1, and first2: ";
    cin >> first1 >> last1 >> first2;

    // Проверка корректности индексов
    if (first1 < 0 || last1 > vec.size() || first1 >= last1 || first2 < 0) {
        cout << "Invalid indices!" << endl;
        return 1;
    }

    // Выбор алгоритма в зависимости от направления сдвига
    if (first2 < first1) {
        // Сдвиг влево, используем copy
        copy(vec.begin() + first1, vec.begin() + last1, vec.begin() + first2);
    }
    else {
        // Сдвиг вправо, используем copy_backward
        copy_backward(vec.begin() + first1, vec.begin() + last1, vec.begin() + first2 + (last1 - first1));
    }

    // Вывод результата
    cout << "Resulting vector: ";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;

    щ