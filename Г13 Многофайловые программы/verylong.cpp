#include "verylong.h"
#include <cstring>
#include <cstdlib>
using namespace std;

verylong::verylong() : vlen(0), isNeg(false) {
    vlstr[0] = '\0';
}

verylong::verylong(const char* num) {
    if (num == nullptr) {
        vlen = 0;
        isNeg = false;
        vlstr[0] = '0';
        return;
    }
    if (num[0] == '-') {
        isNeg = true;
        num++;
    }
    else {
        isNeg = false;
    }
    vlen = strlen(num);
    if (vlen > SZ - 1) vlen = SZ - 1; // Ограничение длины
    for (int i = 0; i < vlen; i++) {
        if (num[i] < '0' || num[i] > '9') {
            vlen = 0;
            isNeg = false;
            vlstr[0] = '0';
            return;
        }
        vlstr[i] = num[vlen - 1 - i];
    }
    trim();
}

verylong::verylong(long n) {
    isNeg = (n < 0);
    if (isNeg) n = -n;
    vlen = 0;
    if (n == 0) {
        vlstr[vlen++] = '0';
    }
    else {
        while (n > 0 && vlen < SZ - 1) {
            vlstr[vlen++] = (n % 10) + '0';
            n /= 10;
        }
    }
    trim();
}

void verylong::trim() {
    while (vlen > 1 && vlstr[vlen - 1] == '0') {
        vlen--;
    }
    if (vlen == 0 || (vlen == 1 && vlstr[0] == '0')) {
        isNeg = false;
        vlen = 1;
        vlstr[0] = '0';
    }
}

void verylong::ensureCapacity(int len) {
    if (len >= SZ) {
        vlen = SZ - 1;
    }
}

int verylong::compare(const verylong& other) const {
    if (isNeg != other.isNeg) return isNeg ? -1 : 1;
    if (vlen != other.vlen) return (isNeg ? -1 : 1) * (vlen > other.vlen ? 1 : -1);
    for (int i = vlen - 1; i >= 0; i--) {
        if (vlstr[i] != other.vlstr[i]) {
            return (isNeg ? -1 : 1) * (vlstr[i] > other.vlstr[i] ? 1 : -1);
        }
    }
    return 0;
}

verylong verylong::operator+(const verylong& other) const {
    verylong result;
    if (isNeg == other.isNeg) {
        result.isNeg = isNeg;
        int carry = 0;
        int maxLen = max(vlen, other.vlen);
        result.ensureCapacity(maxLen + 1);
        result.vlen = maxLen;

        for (int i = 0; i < maxLen || carry; i++) {
            if (i < result.vlen) {
                int sum = carry;
                if (i < vlen) sum += vlstr[i] - '0';
                if (i < other.vlen) sum += other.vlstr[i] - '0';
                carry = sum / 10;
                result.vlstr[i] = (sum % 10) + '0';
            }
        }
        if (carry) result.vlstr[result.vlen++] = carry + '0';
    }
    else {
        // Преобразуем в вычитание
        verylong temp = other;
        temp.isNeg = !temp.isNeg;
        result = *this - temp;
    }
    result.trim();
    return result;
}

verylong verylong::operator-(const verylong& other) const {
    verylong result;
    int cmp = compare(other);
    if (cmp == 0) return verylong(0L);

    if (isNeg != other.isNeg) {
        result = *this + verylong(other.vlstr);
        result.isNeg = isNeg;
    }
    else {
        bool resultNeg = (cmp < 0) ^ isNeg;
        const verylong& larger = (cmp > 0) ? *this : other;
        const verylong& smaller = (cmp > 0) ? other : *this;

        int borrow = 0;
        result.vlen = larger.vlen;
        result.ensureCapacity(result.vlen);

        for (int i = 0; i < larger.vlen; i++) {
            int diff = (larger.vlstr[i] - '0') - (i < smaller.vlen ? smaller.vlstr[i] - '0' : 0) - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            result.vlstr[i] = diff + '0';
        }
        result.isNeg = resultNeg;
    }
    result.trim();
    return result;
}

verylong verylong::operator*(const verylong& other) const {
    verylong result;
    result.vlen = vlen + other.vlen;
    result.ensureCapacity(result.vlen);
    result.isNeg = isNeg != other.isNeg;

    for (int i = 0; i < result.vlen; i++) result.vlstr[i] = '0';

    for (int i = 0; i < vlen; i++) {
        int carry = 0;
        for (int j = 0; j < other.vlen; j++) {
            int mul = (vlstr[i] - '0') * (other.vlstr[j] - '0') + carry;
            if (i + j < result.vlen) {
                int temp = (result.vlstr[i + j] - '0') + (mul % 10);
                carry = mul / 10 + temp / 10;
                result.vlstr[i + j] = (temp % 10) + '0';
            }
        }
        if (i + other.vlen < result.vlen && carry) {
            result.vlstr[i + other.vlen] = carry + '0';
        }
    }
    result.trim();
    return result;
}

verylong verylong::operator/(const verylong& other) const {
    if (other.vlen == 1 && other.vlstr[0] == '0') {
        cout << "Ошибка: деление на ноль!" << endl;
        return verylong(0L);
    }

    verylong result(0L);
    verylong dividend = *this;
    verylong divisor = other;

    result.isNeg = isNeg != other.isNeg;
    dividend.isNeg = false;
    divisor.isNeg = false;

    if (dividend.compare(divisor) < 0) return verylong(0L);

    verylong remainder(0L);
    result.vlen = dividend.vlen;
    result.ensureCapacity(result.vlen);

    for (int i = dividend.vlen - 1; i >= 0; i--) {
        remainder = remainder * verylong(10L) + verylong(dividend.vlstr[i] - '0');
        int count = 0;
        while (remainder.compare(divisor) >= 0) {
            remainder = remainder - divisor;
            count++;
        }
        if (i < result.vlen) result.vlstr[i] = count + '0';
    }

    result.trim();
    return result;
}

ostream& operator<<(ostream& os, const verylong& v) {
    if (v.vlen == 0 || (v.vlen == 1 && v.vlstr[0] == '0')) {
        os << "0";
        return os;
    }
    if (v.isNeg) os << "-";
    for (int i = v.vlen - 1; i >= 0; i--) {
        os << v.vlstr[i];
    }
    return os;
}