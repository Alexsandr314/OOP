// warehouse.cpp
#include "warehouse.h"
#include <clocale>
#include <iomanip> // Для форматирования таблицы
#ifdef _WIN32
#include <windows.h>
#endif

void getaLine(string& inStr) {
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n');
    inStr = temp;
}

char getaChar() {
    char ch = cin.get();
    cin.ignore(80, '\n');
    return ch;
}

// Методы класса Admin
void Admin::addUser(vector<User>& users, int roleIndex, string login, string password) {
    string role;
    switch (roleIndex) {
    case 1: role = "WarehouseManager"; break;
    case 2: role = "SalesAgent"; break;
    case 3: role = "Accountant"; break;
    case 4: role = "Director"; break;
    default: role = "Unknown"; break;
    }
    users.push_back(User(login, password, role));
    cout << "Пользователь " << login << " с ролью " << role << " добавлен.\n";
}

void Admin::removeUser(vector<User>& users, string login) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->login == login) {
            users.erase(it);
            cout << "Пользователь " << login << " удален.\n";
            return;
        }
    }
    cout << "Пользователь не найден.\n";
}

// Методы класса Director
void Director::viewReports(const map<int, Item>& stock) {
    cout << "\nОтчет по складу:\n";
    if (stock.empty()) {
        cout << "Склад пуст.\n";
    }
    else {
        for (const auto& item : stock) {
            if (item.second.quantity > 0) {
                cout << "ID: " << item.first << ", Товар: " << item.second.name
                    << ", Количество: " << item.second.quantity
                    << ", Цена: " << item.second.price << " руб.\n";
            }
        }
    }
}

void Director::viewAgentActivity(const vector<Sale>& sales) {
    cout << "\nРабота торговых агентов:\n";
    if (sales.empty()) {
        cout << "Продаж нет.\n";
    }
    else {
        for (const auto& sale : sales) {
            cout << "ID: " << sale.itemId << ", Товар: " << sale.itemName
                << ", Количество: " << sale.quantity
                << ", Цена за единицу: " << sale.price << " руб."
                << ", Магазин: " << sale.store << "\n";
        }
    }
}

void Director::viewTaxReport(const vector<Sale>& sales) {
    if (sales.empty()) {
        cout << "Нет данных для отчета по налогам, так как продаж не было.\n";
        return;
    }

    double totalRevenue = 0.0;
    double totalTax = 0.0;
    const double taxRate = 0.20; // Налог 20%

    cout << "\nПодробный отчет по налогам:\n";
    cout << "------------------------------------------------------------\n";
    cout << "ID | Товар          | Кол-во | Цена (руб.) | Сумма (руб.) | Налог (руб.)\n";
    cout << "------------------------------------------------------------\n";

    for (const auto& sale : sales) {
        double saleAmount = sale.quantity * sale.price;
        double saleTax = saleAmount * taxRate;
        totalRevenue += saleAmount;
        totalTax += saleTax;

        cout << sale.itemId << "  | "
            << setw(15) << left << sale.itemName << "| "
            << setw(7) << sale.quantity << "| "
            << setw(12) << fixed << setprecision(2) << sale.price << "| "
            << setw(12) << saleAmount << "| "
            << setw(12) << saleTax << "\n";
    }

    cout << "------------------------------------------------------------\n";
    cout << "Итого:\n";
    cout << "Общая выручка: " << totalRevenue << " руб.\n";
    cout << "Общий налог (" << (taxRate * 100) << "%): " << totalTax << " руб.\n";
}

// Методы класса SalesAgent
void SalesAgent::viewStock(const map<int, Item>& stock) {
    cout << "\nСписок товаров на складе:\n";
    if (stock.empty()) {
        cout << "Склад пуст.\n";
    }
    else {
        bool hasItems = false;
        for (const auto& item : stock) {
            if (item.second.quantity > 0) {
                cout << "ID: " << item.first << ", Товар: " << item.second.name
                    << ", Количество: " << item.second.quantity
                    << ", Цена: " << item.second.price << " руб.\n";
                hasItems = true;
            }
        }
        if (!hasItems) {
            cout << "Склад пуст (все товары с нулевым количеством).\n";
        }
    }
}

void SalesAgent::sellItem(vector<Sale>& sales, map<int, Item>& stock, int id, int qty, string store) {
    auto it = stock.find(id);
    if (it != stock.end() && it->second.quantity >= qty) {
        it->second.quantity -= qty;
        sales.push_back(Sale(id, it->second.name, qty, it->second.price, store));
        if (it->second.quantity == 0) {
            stock.erase(it);
        }
        cout << "Товар " << it->second.name << " (ID: " << id << ") продан в количестве " << qty << " в магазин " << store << ".\n";
    }
    else {
        cout << "Недостаточно товара или товар с ID " << id << " не найден.\n";
    }
}

void SalesAgent::sendToAccounting(const vector<Sale>& sales) {
    cout << "Данные о продажах отправлены в бухгалтерию:\n";
    for (const auto& sale : sales) {
        cout << "ID: " << sale.itemId << ", Товар: " << sale.itemName
            << ", Количество: " << sale.quantity
            << ", Цена за единицу: " << sale.price << " руб."
            << ", Магазин: " << sale.store << "\n";
    }
}

void SalesAgent::viewSoldItemsCount(const vector<Sale>& sales) {
    if (sales.empty()) {
        cout << "\nПродаж еще не было.\n";
        return;
    }

    time_t now = time(0);
    const Sale& lastSale = sales.back();
    double secondsSinceLastSale = difftime(now, lastSale.saleTime);
    int minutes = static_cast<int>(secondsSinceLastSale / 60);
    int seconds = static_cast<int>(secondsSinceLastSale) % 60;

    struct tm saleTime;
    localtime_s(&saleTime, &lastSale.saleTime);
    char timeStr[26];
    asctime_s(timeStr, sizeof(timeStr), &saleTime);

    cout << "\nПоследняя продажа была в " << timeStr;
    cout << "Прошло времени с последней продажи: " << minutes << " минут и " << seconds << " секунд.\n";
    cout << "ID: " << lastSale.itemId << ", Товар: " << lastSale.itemName
        << ", Количество: " << lastSale.quantity
        << ", Цена за единицу: " << lastSale.price << " руб."
        << ", Магазин: " << lastSale.store << "\n";
}

// Методы класса Accountant
void Accountant::createInvoice(const vector<Sale>& sales) {
    cout << "Накладная создана на основе продаж:\n";
    for (const auto& sale : sales) {
        cout << "ID: " << sale.itemId << ", Товар: " << sale.itemName
            << ", Количество: " << sale.quantity
            << ", Цена за единицу: " << sale.price << " руб."
            << ", Магазин: " << sale.store << "\n";
    }
}

void Accountant::viewTaxReport(const vector<Sale>& sales) {
    if (sales.empty()) {
        cout << "Нет данных для отчета по налогам, так как продаж не было.\n";
        return;
    }

    double totalRevenue = 0.0;
    double totalTax = 0.0;
    const double taxRate = 0.20; // Налог 20%

    cout << "\nПодробный отчет по налогам:\n";
    cout << "------------------------------------------------------------\n";
    cout << "ID | Товар          | Кол-во | Цена (руб.) | Сумма (руб.) | Налог (руб.)\n";
    cout << "------------------------------------------------------------\n";

    for (const auto& sale : sales) {
        double saleAmount = sale.quantity * sale.price;
        double saleTax = saleAmount * taxRate;
        totalRevenue += saleAmount;
        totalTax += saleTax;

        cout << sale.itemId << "  | "
            << setw(15) << left << sale.itemName << "| "
            << setw(7) << sale.quantity << "| "
            << setw(12) << fixed << setprecision(2) << sale.price << "| "
            << setw(12) << saleAmount << "| "
            << setw(12) << saleTax << "\n";
    }

    cout << "------------------------------------------------------------\n";
    cout << "Итого:\n";
    cout << "Общая выручка: " << totalRevenue << " руб.\n";
    cout << "Общий налог (" << (taxRate * 100) << "%): " << totalTax << " руб.\n";
    cout << "Отчет по налогам отправлен в налоговую инспекцию.\n";
}

void Accountant::sendDataToWarehouse(const vector<Sale>& sales) {
    cout << "Данные о продажах отправлены заведующему складом:\n";
    for (const auto& sale : sales) {
        cout << "ID: " << sale.itemId << ", Товар: " << sale.itemName
            << ", Количество: " << sale.quantity
            << ", Цена за единицу: " << sale.price << " руб."
            << ", Магазин: " << sale.store << "\n";
    }
}

// Методы класса WarehouseManager
void WarehouseManager::manageStock(const map<int, Item>& stock) {
    cout << "\nОстатки на складе:\n";
    if (stock.empty()) {
        cout << "Склад пуст.\n";
    }
    else {
        bool hasItems = false;
        for (const auto& item : stock) {
            if (item.second.quantity > 0) {
                cout << "ID: " << item.first << ", Товар: " << item.second.name
                    << ", Количество: " << item.second.quantity
                    << ", Цена: " << item.second.price << " руб.\n";
                hasItems = true;
            }
        }
        if (!hasItems) {
            cout << "Склад пуст (все товары с нулевым количеством).\n";
        }
    }
}

void WarehouseManager::shipItem(map<int, Item>& stock, const vector<Sale>& sales) {
    cout << "Отгрузка по продажам:\n";
    for (const auto& sale : sales) {
        cout << "ID: " << sale.itemId << ", Товар: " << sale.itemName
            << ", Количество: " << sale.quantity
            << ", Цена за единицу: " << sale.price << " руб."
            << ", Магазин: " << sale.store << "\n";
    }
}

void WarehouseManager::addStock(map<int, Item>& stock, int id, string name, int qty, double price) {
    stock[id] = Item(id, name, qty, price); // Используем параметризованный конструктор
    cout << "Товар " << name << " (ID: " << id << ") добавлен на склад в количестве " << qty << " по цене " << price << " руб.\n";
}

void WarehouseManager::viewSoldItemsToday(const vector<Sale>& sales) {
    time_t now = time(0);
    struct tm tm_now;
    localtime_s(&tm_now, &now);
    tm_now.tm_hour = 0;
    tm_now.tm_min = 0;
    tm_now.tm_sec = 0;
    time_t startOfDay = mktime(&tm_now);

    char timeStr[26];
    asctime_s(timeStr, sizeof(timeStr), &tm_now);
    cout << "\nПроданные товары за сегодня (" << timeStr << "):\n";
    bool found = false;
    for (const auto& sale : sales) {
        if (difftime(sale.saleTime, startOfDay) >= 0) {
            struct tm saleTime;
            localtime_s(&saleTime, &sale.saleTime);
            char saleTimeStr[26];
            asctime_s(saleTimeStr, sizeof(saleTimeStr), &saleTime);
            cout << "ID: " << sale.itemId << ", Товар: " << sale.itemName
                << ", Количество: " << sale.quantity
                << ", Цена за единицу: " << sale.price << " руб."
                << ", Магазин: " << sale.store
                << ", Время продажи: " << saleTimeStr;
            found = true;
        }
    }
    if (!found) {
        cout << "Продаж за сегодня нет.\n";
    }

    if (found) {
        const Sale& lastSale = sales.back();
        double secondsSinceLastSale = difftime(now, lastSale.saleTime);
        int minutes = static_cast<int>(secondsSinceLastSale / 60);
        int seconds = static_cast<int>(secondsSinceLastSale) % 60;
        cout << "\nПоследняя продажа была " << minutes << " минут и " << seconds << " секунд назад.\n";
    }
}

void WarehouseManager::sendStockReport(const map<int, Item>& stock) {
    cout << "Отчет по поступлению отправлен:\n";
    if (stock.empty()) {
        cout << "Склад пуст.\n";
    }
    else {
        for (const auto& item : stock) {
            if (item.second.quantity > 0) {
                cout << "ID: " << item.first << ", Товар: " << item.second.name
                    << ", Количество: " << item.second.quantity
                    << ", Цена: " << item.second.price << " руб.\n";
            }
        }
    }
}

// Методы класса Warehouse
void Warehouse::displayStock() const {
    cout << "\nСписок товаров на складе:\n";
    if (stock.empty()) {
        cout << "Склад пуст.\n";
    }
    else {
        bool hasItems = false;
        for (const auto& item : stock) {
            if (item.second.quantity > 0) {
                cout << "ID: " << item.first << ", Товар: " << item.second.name
                    << ", Количество: " << item.second.quantity
                    << ", Цена: " << item.second.price << " руб.\n";
                hasItems = true;
            }
        }
        if (!hasItems) {
            cout << "Склад пуст (все товары с нулевым количеством).\n";
        }
    }
}

// Методы класса Menu
Menu::Menu() : nextItemId(1) { // Инициализация счетчика ID
    // Инициализация начального пользователя
    users.push_back(User("max2001", "max01", "SalesAgent"));
}

void Menu::showLoginMenu() {
    string login, password;
    while (true) {
        cout << "=== Добро пожаловать в систему управления складом ===\n";
        cout << "Логин: ";
        getaLine(login);
        cout << "Пароль: ";
        getaLine(password);

        // Проверка логина и пароля
        if (login == "admin" && password == "admin") {
            showAdminMenu();
        }
        else {
            bool found = false;
            for (const auto& user : users) {
                if (user.login == login && user.password == password) {
                    found = true;
                    if (user.role == "SalesAgent") {
                        showSalesAgentMenu();
                    }
                    else if (user.role == "WarehouseManager") {
                        showWarehouseMenu();
                    }
                    else if (user.role == "Accountant") {
                        showAccountantMenu();
                    }
                    else if (user.role == "Director") {
                        showDirectorMenu();
                    }
                }
            }
            if (!found) {
                cout << "Неверный логин или пароль.\n";
            }
        }
    }
}

void Menu::showAdminMenu() {
    char choice;
    while (true) {
        cout << "\n=== Меню Администратора ===\n";
        cout << "1. Добавить пользователя\n";
        cout << "2. Удалить пользователя\n";
        cout << "3. Выход\n";
        cout << "Выберите действие: ";
        choice = getaChar();
        if (choice == '1') {
            string login, password;
            cout << "Логин: "; getaLine(login);
            cout << "Пароль: "; getaLine(password);
            cout << "Роль (1 - Заведующий складом, 2 - Торговый агент, 3 - Бухгалтер, 4 - Директор): ";
            int role; cin >> role; cin.ignore(80, '\n');
            admin.addUser(users, role, login, password);
        }
        else if (choice == '2') {
            string login;
            cout << "Логин для удаления: "; getaLine(login);
            admin.removeUser(users, login);
        }
        else if (choice == '3') {
            break;
        }
    }
}

void Menu::showSalesAgentMenu() {
    char choice;
    while (true) {
        cout << "\n=== Меню Торгового агента ===\n";
        cout << "1. Просмотр остатков на складе\n";
        cout << "2. Продать товар\n";
        cout << "3. Отправить данные в бухгалтерию\n";
        cout << "4. Посмотреть время последней продажи\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        choice = getaChar();
        if (choice == '1') salesAgent.viewStock(warehouse.stock);
        else if (choice == '2') {
            int id, qty;
            string store;
            cout << "ID товара: "; cin >> id; cin.ignore(80, '\n');
            cout << "Количество: "; cin >> qty; cin.ignore(80, '\n');
            cout << "Магазин: "; getaLine(store);
            salesAgent.sellItem(sales, warehouse.stock, id, qty, store);
        }
        else if (choice == '3') {
            salesAgent.sendToAccounting(sales);
        }
        else if (choice == '4') {
            salesAgent.viewSoldItemsCount(sales);
        }
        else if (choice == '5') break;
    }
}

void Menu::showDirectorMenu() {
    char choice;
    while (true) {
        cout << "\n=== Меню Директора ===\n";
        cout << "1. Просмотреть отчеты по складу\n";
        cout << "2. Просмотреть работу агентов\n";
        cout << "3. Просмотреть отчет по налогам\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";
        choice = getaChar();
        if (choice == '1') director.viewReports(warehouse.stock);
        else if (choice == '2') director.viewAgentActivity(sales);
        else if (choice == '3') director.viewTaxReport(sales);
        else if (choice == '4') break;
    }
}

void Menu::showAccountantMenu() {
    char choice;
    while (true) {
        cout << "\n=== Меню Бухгалтера ===\n";
        cout << "1. Создать накладную\n";
        cout << "2. Просмотреть отчет по налогам\n";
        cout << "3. Отправить данные заведующему складом\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";
        choice = getaChar();
        if (choice == '1') accountant.createInvoice(sales);
        else if (choice == '2') accountant.viewTaxReport(sales);
        else if (choice == '3') accountant.sendDataToWarehouse(sales);
        else if (choice == '4') break;
    }
}

void Menu::showWarehouseMenu() {
    char choice;
    while (true) {
        cout << "\n=== Меню Заведующего складом ===\n";
        cout << "1. Просмотреть остатки\n";
        cout << "2. Добавить товар\n";
        cout << "3. Отгрузить товар по продажам\n";
        cout << "4. Просмотреть проданные товары за сегодня\n";
        cout << "5. Отправить отчет по поступлению\n";
        cout << "6. Выход\n";
        cout << "Выберите действие: ";
        choice = getaChar();
        if (choice == '1') warehouseManager.manageStock(warehouse.stock);
        else if (choice == '2') {
            string name; int qty; double price;
            cout << "Название товара: "; getaLine(name);
            cout << "Количество: "; cin >> qty; cin.ignore(80, '\n');
            cout << "Цена за единицу (руб.): "; cin >> price; cin.ignore(80, '\n');
            warehouseManager.addStock(warehouse.stock, nextItemId++, name, qty, price);
        }
        else if (choice == '3') warehouseManager.shipItem(warehouse.stock, sales);
        else if (choice == '4') warehouseManager.viewSoldItemsToday(sales);
        else if (choice == '5') warehouseManager.sendStockReport(warehouse.stock);
        else if (choice == '6') break;
    }
}