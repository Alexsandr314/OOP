#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

int main() {
    // ���� ���� ������
    string input_file, output_file;
    cout << "Enter input file name: ";
    cin >> input_file;
    cout << "Enter output file name: ";
    cin >> output_file;

    // �������� �������� �����
    ifstream ifs(input_file);
    if (!ifs.is_open()) {
        cout << "Cannot open input file!" << endl;
        return 1;
    }

    // �������� ��������� �����
    ofstream ofs(output_file);
    if (!ofs.is_open()) {
        cout << "Cannot open output file!" << endl;
        return 1;
    }

    // ����������� � �������������� ��������� ����������
    istream_iterator<int> input_iter(ifs), input_end;
    ostream_iterator<int> output_iter(ofs, " ");

    while (input_iter != input_end) {
        *output_iter = *input_iter;
        ++input_iter;
        ++output_iter;
    }

    cout << "File copied successfully." << endl;
    return 0;
}