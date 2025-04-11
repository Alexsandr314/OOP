#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int NUMARRAYS = 10;
    const int MAXSIZE = 10;

    int a0[MAXSIZE], a1[MAXSIZE], a2[MAXSIZE], a3[MAXSIZE], a4[MAXSIZE];
    int a5[MAXSIZE], a6[MAXSIZE], a7[MAXSIZE], a8[MAXSIZE], a9[MAXSIZE];

    int* ap[NUMARRAYS] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };

    for (int j = 0; j < NUMARRAYS; j++) {
        for (int k = 0; k < MAXSIZE; k++) {
            ap[j][k] = j * MAXSIZE * 10 + k * 10;
        }
    }

    cout << "Содержимое массивов:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "Массив " << j << ": ";
        for (int k = 0; k < MAXSIZE; k++) {
            cout << ap[j][k] << " ";
        }
        cout << endl;
    }

    return 0;
}