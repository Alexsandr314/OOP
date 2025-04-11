#include <iostream>
using namespace std;

void addarrays(float* arr1, float* arr2, float* result, int size) {
    for (int i = 0; i < size; i++) {
        *(result + i) = *(arr1 + i) + *(arr2 + i);
    }
}

int main() {
	setlocale(LC_ALL, "Russian");
    const int SIZE = 5;
    float arr1[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    float arr2[SIZE] = { 5.5, 4.4, 3.3, 2.2, 1.1 };
    float result[SIZE];

    addarrays(arr1, arr2, result, SIZE);

    cout << "Результат сложения массивов:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << *(result + i) << " ";
    }
    cout << endl;   

    return 0;
}