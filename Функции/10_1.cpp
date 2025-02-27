#include <iostream>
#include <locale>

using namespace std;

int counter = 0; // ���������� ���������� ��� �������� �������

// ������� � �������������� ���������� ����������
void callCountGlobal() {
    counter++;
    cout << "������� ������� " << counter << " ���(�)." << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    // ����� ������� 10 ���
    for (int i = 0; i < 10; i++) {
        callCountGlobal();
    }

    return 0;
}

//#include <iostream>
//#include <locale>
//
//using namespace std;
//
//// ������� � �������������� ����������� ��������� ����������
//void callCountStatic() {
//    static int counter = 0; // ����������� ����������
//    counter++;
//    cout << "������� ������� " << counter << " ���(�)." << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    // ����� ������� 10 ���
//    for (int i = 0; i < 10; i++) {
//        callCountStatic();
//    }
//
//    return 0;
//}
