#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int NUMARRAYS = 10;
    const int MAXSIZE = 10;

    int* ap[NUMARRAYS];

    for (int j = 0; j < NUMARRAYS; j++) {
        *(ap + j) = new int[MAXSIZE];
    }

    for (int j = 0; j < NUMARRAYS; j++) {
        for (int k = 0; k < MAXSIZE; k++) {
            *(*(ap + j) + k) = j * MAXSIZE * 10 + k * 10;
        }
    }

    cout << "Содержимое массивов:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "Массив " << j << ": ";
        for (int k = 0; k < MAXSIZE; k++) {
            cout << *(*(ap + j) + k) << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < NUMARRAYS; j++) {
        delete[] * (ap + j);
    }

    return 0;
}