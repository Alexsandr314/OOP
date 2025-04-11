#include <iostream>
#include <clocale>
using namespace std;

const int FMEM_SIZE = 100;
const int PMEM_SIZE = 100;

class Float {
private:
    static float fmemory[FMEM_SIZE];
    static int fmem_top;
    int addr;
public:
    Float(float value) {
        if (fmem_top >= FMEM_SIZE) {
            cout << "Ошибка: память fmemory переполнена\n";
            addr = -1;
            return;
        }
        *(fmemory + fmem_top) = value;
        addr = fmem_top;
        fmem_top++;
    }
    int& operator&() {
        return addr;
    }
};

class ptrFloat {
private:
    static int pmemory[PMEM_SIZE];
    static int pmem_top;
    int addr;
public:
    ptrFloat(int address) {
        if (pmem_top >= PMEM_SIZE) {
            cout << "Ошибка: память pmemory переполнена\n";
            addr = -1;
            return;
        }
        *(pmemory + pmem_top) = address;
        addr = pmem_top;
        pmem_top++;
    }
    float& operator*() {
        if (addr < 0 || addr >= PMEM_SIZE || *(pmemory + addr) < 0) {
            cout << "Ошибка: недопустимый адрес\n";
            static float dummy = 0.0;
            return dummy;
        }
        return *(fmemory + *(pmemory + addr));
    }
};

// Инициализация статических членов
float Float::fmemory[FMEM_SIZE];
int Float::fmem_top = 0;
int ptrFloat::pmemory[PMEM_SIZE];
int ptrFloat::pmem_top = 0;

int main() {
    setlocale(LC_ALL, "Russian");

    Float var1 = 1.234;
    Float var2 = 5.678;
    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    *ptr1 = 7.123;
    *ptr2 = 8.456;

    cout << "После присваивания:\n";
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}