#include "elevator.h"
#include <limits>

elevator::elevator() : current_floor(0), current_dir(STOP), loading_timer(0), unloading_timer(0), destination(false) {
    // Инициализация лифта на первом этаже (0)
}

void elevator::tick() {
    display(); // Вывод состояния

    // Обработка таймеров
    if (loading_timer > 0) --loading_timer;
    if (unloading_timer > 0) --unloading_timer;

    // Если есть назначение и лифт на месте
    if (destination && loading_timer == 0 && unloading_timer == 0) {
        if (current_floor < NUM_FLOORS - 1 && current_dir == UP) {
            current_floor++;
        }
        else if (current_floor > 0 && current_dir == DN) {
            current_floor--;
        }
        else if (current_floor == NUM_FLOORS - 1 || current_floor == 0) {
            current_dir = STOP;
        }
        if (current_floor == (destination ? NUM_FLOORS - 1 : 0)) {
            unloading_timer = LOAD_TIME;
            destination = false;
        }
    }
}

void elevator::display() const {
    cout << "Лифт на этаже: " << current_floor + 1 << endl;
    cout << "Направление: ";
    switch (current_dir) {
    case UP: cout << "Вверх" << endl; break;
    case DN: cout << "Вниз" << endl; break;
    case STOP: cout << "Остановлен" << endl; break;
    }
    cout << "Состояние: ";
    if (loading_timer > 0) cout << "Загрузка (" << loading_timer << ")" << endl;
    else if (unloading_timer > 0) cout << "Выгрузка (" << unloading_timer << ")" << endl;
    else cout << "Готов" << endl;
}

void elevator::set_destination(int floor) {
    if (floor > 0 && floor <= NUM_FLOORS) {
        destination = true;
        current_dir = (floor > current_floor + 1) ? UP : DN;
    }
    else {
        cout << "Неверный этаж! Введите число от 1 до " << NUM_FLOORS << endl;
    }
}

void elevator::get_destination() {
    int floor;
    cout << "Введите этаж назначения (1-" << NUM_FLOORS << ", 0 для выхода): ";
    cin >> floor;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    if (floor == 0) return;
    set_destination(floor - 1); // Смещение на 0-based индекс
}

int elevator::get_floor() const {
    return current_floor;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа управления одним лифтом" << endl;

    elevator lift;
    while (true) {
        lift.tick();
        lift.get_destination();
        if (cin.eof()) break; // Выход при Ctrl+Z или Ctrl+D
    }
    return 0;
}