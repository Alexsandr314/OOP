#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {
    // Ввод имени файла
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    // Открытие файла
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    // Создание отображения для частотной таблицы
    map<string, int> freq_table;

    string word;
    string current_word;
    char c;
    while (ifs.get(c)) {
        if (isalpha(c)) {
            current_word += tolower(c);
        }
        else if (ispunct(c) || isspace(c)) {
            if (!current_word.empty()) {
                freq_table[current_word]++;
                current_word.clear();
            }
        }
    }
    // Проверка последнего слова
    if (!current_word.empty()) {
        freq_table[current_word]++;
    }

    // Вывод частотной таблицы
    cout << "Frequency table:\n";
    for (const auto& pair : freq_table) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}