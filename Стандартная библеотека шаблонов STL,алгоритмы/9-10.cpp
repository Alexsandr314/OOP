#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

int main() {
    // �������� � ������������� ������� �����
    vector<string> names = { "Alice", "Bob", "Charlie", "David", "Eve" };

    // ���� ������ ��� ������
    string search_name;
    cout << "Enter name to search: ";
    cin >> search_name;

    // ����� ������ � �������������� bind2nd � equal_to
    auto it = find_if(names.begin(), names.end(),
        bind2nd(equal_to<string>(), search_name));

    // ����� ����������
    if (it != names.end()) {
        cout << "Found " << search_name << " at position: "
            << distance(names.begin(), it) << endl;
    }
    else {
        cout << search_name << " not found in the container." << endl;
    }

    return 0;
}