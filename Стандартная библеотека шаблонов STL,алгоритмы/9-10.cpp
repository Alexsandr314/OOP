#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

int main() {
    // Создание и инициализация вектора строк
    vector<string> names = { "Alice", "Bob", "Charlie", "David", "Eve" };

    // Ввод строки для поиска
    string search_name;
    cout << "Enter name to search: ";
    cin >> search_name;

    // Поиск строки с использованием bind2nd и equal_to
    auto it = find_if(names.begin(), names.end(),
        bind2nd(equal_to<string>(), search_name));

    // Вывод результата
    if (it != names.end()) {
        cout << "Found " << search_name << " at position: "
            << distance(names.begin(), it) << endl;
    }
    else {
        cout << search_name << " not found in the container." << endl;
    }

    return 0;
}