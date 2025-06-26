#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {
    // ���� ����� �����
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    // �������� �����
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    // �������� ����������� ��� ��������� �������
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
    // �������� ���������� �����
    if (!current_word.empty()) {
        freq_table[current_word]++;
    }

    // ����� ��������� �������
    cout << "Frequency table:\n";
    for (const auto& pair : freq_table) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}