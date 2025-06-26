#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // �������� � ������������� �������
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // ���� �������
    int first1, last1, first2;
    cout << "Enter first1, last1, and first2: ";
    cin >> first1 >> last1 >> first2;

    // �������� ������������ ��������
    if (first1 < 0 || last1 > vec.size() || first1 >= last1 || first2 < 0) {
        cout << "Invalid indices!" << endl;
        return 1;
    }

    // �������� �� ���������� (first2 �� ������ ���� ������ [first1, last1) ��� ������ last1)
    if (first2 >= first1 && first2 < last1) {
        cout << "Invalid: destination overlaps with source and is not to the left!" << endl;
        return 1;
    }

    // ����������� ������������������
    copy(vec.begin() + first1, vec.begin() + last1, vec.begin() + first2);

    // ����� ����������
    cout << "Resulting vector: ";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}