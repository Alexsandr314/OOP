#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    // �������� � ���������� ������� ������� �������
    array<int, 10> even_numbers;
    for (size_t i = 0; i < even_numbers.size(); ++i) {
        even_numbers[i] = (i + 1) * 2; // ������ �����: 2, 4, 6, ..., 20
    }

    // �������� � ���������� ��������� ��������� �������
    set<int> odd_numbers;
    for (int i = 1; i <= 20; i += 2) {
        odd_numbers.insert(i); // �������� �����: 1, 3, 5, ..., 19
    }

    // �������� ������� ��� ���������� �������
    vector<int> merged_vector(even_numbers.size() + odd_numbers.size());

    // ������� ��������������� �������������������
    merge(even_numbers.begin(), even_numbers.end(),
        odd_numbers.begin(), odd_numbers.end(),
        merged_vector.begin());

    // ����� ����������� �������
    cout << "Merged vector: ";
    for (const auto& num : merged_vector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}