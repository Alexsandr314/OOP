#include <iostream>
#include <clocale>
using namespace std;

int compstr(char* s1, char* s2) {
    while (*s1 && *s2) {
        if (*s1 < *s2) return -1;
        if (*s1 > *s2) return 1;
        s1++;
        s2++;
    }
    if (*s1) return 1;
    if (*s2) return -1;
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char str1[] = "яблоко";
    char str2[] = "банан";
    char str3[] = "яблоко";

    cout << "Сравнение \"" << str1 << "\" и \"" << str2 << "\": " << compstr(str1, str2) << endl;
    cout << "Сравнение \"" << str2 << "\" и \"" << str1 << "\": " << compstr(str2, str1) << endl;
    cout << "Сравнение \"" << str1 << "\" и \"" << str3 << "\": " << compstr(str1, str3) << endl;

    return 0;
}