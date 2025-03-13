#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class money {
public:
    static string ldtoms(long double value) {
        if (value > 9'999'999'999'999'990.00) {
            return "Ошибка: слишком большое значение!";
        }

        // Создаем поток для форматированного вывода
        ostringstream oss;
        oss << fixed << setprecision(2) << value;
        string ustring = oss.str();

        // Разбираем целую и дробную части
        size_t dot_pos = ustring.find('.');
        string integer_part = ustring.substr(0, dot_pos);
        string fractional_part = ustring.substr(dot_pos);

        // Убираем ведущие нули
        while (integer_part.length() > 1 && integer_part[0] == '0') {
            integer_part.erase(0, 1);
        }

        // Форматируем число с запятыми
        string formatted = "$";
        int count = 0;
        for (int i = integer_part.length() - 1; i >= 0; i--) {
            formatted = integer_part[i] + formatted;
            count++;
            if (count % 3 == 0 && i != 0) {
                formatted = ',' + formatted;
            }
        }

        formatted += fractional_part;
        return formatted;
    }
};

int main() {
    long double value;
    cout << "Введите число: ";
    cin >> value;

    cout << "Денежная строка: " << money::ldtoms(value) << endl;

    return 0;
}
