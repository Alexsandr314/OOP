#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // �������� � ������������� �������
    vector<double> fares = { 100.50, 200.75, 150.25, 300.00 };

    // ���������� ����� � �������������� accumulate � ����� �����������
    double total = accumulate(fares.begin(), fares.end(), 0.0);

    // ����� ����������
    cout << "Total fares: " << total << endl;

    return 0;
}