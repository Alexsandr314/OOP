// warehouse.h
#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

void getaLine(string& inStr);
char getaChar();

// Класс для пользователя
class User {
public:
    string login;
    string password;
    string role;
    User(string l, string p, string r) : login(l), password(p), role(r) {}
};

// Класс для товара
class Item {
public:
    int id; // Уникальный идентификатор товара
    string name;
    int quantity;
    double price; // Цена товара
    Item() : id(0), name(""), quantity(0), price(0.0) {} // Конструктор по умолчанию
    Item(int i, string n, int q, double p) : id(i), name(n), quantity(q), price(p) {}
};

// Класс для продажи
class Sale {
public:
    int itemId; // ID товара
    string itemName;
    int quantity;
    double price; // Цена за единицу на момент продажи
    string store;
    time_t saleTime;
    Sale(int i, string n, int q, double p, string s) : itemId(i), itemName(n), quantity(q), price(p), store(s), saleTime(time(0)) {}
};

// Класс для администратора
class Admin {
public:
    void addUser(vector<User>& users, int roleIndex, string login, string password);
    void removeUser(vector<User>& users, string login);
};

// Класс для бухгалтера
class Accountant {
public:
    void createInvoice(const vector<Sale>& sales);
    void viewTaxReport(const vector<Sale>& sales);
    void sendDataToWarehouse(const vector<Sale>& sales);
};

// Класс для директора
class Director {
public:
    void viewReports(const map<int, Item>& stock);
    void viewAgentActivity(const vector<Sale>& sales);
    void viewTaxReport(const vector<Sale>& sales); // Новый метод для просмотра отчета по налогам
};

// Класс для торгового агента
class SalesAgent {
public:
    void viewStock(const map<int, Item>& stock);
    void sellItem(vector<Sale>& sales, map<int, Item>& stock, int id, int qty, string store);
    void sendToAccounting(const vector<Sale>& sales);
    void viewSoldItemsCount(const vector<Sale>& sales);
};

// Класс для заведующего складом
class WarehouseManager {
public:
    void manageStock(const map<int, Item>& stock);
    void shipItem(map<int, Item>& stock, const vector<Sale>& sales);
    void addStock(map<int, Item>& stock, int id, string name, int qty, double price);
    void viewSoldItemsToday(const vector<Sale>& sales);
    void sendStockReport(const map<int, Item>& stock);
};

// Класс для склада
class Warehouse {
public:
    map<int, Item> stock; // Карта: ID товара -> объект Item
    void displayStock() const;
};

// Класс для меню
class Menu {
private:
    vector<User> users;
    vector<Sale> sales;
    Admin admin;
    Warehouse warehouse;
    SalesAgent salesAgent;
    Director director;
    Accountant accountant;
    WarehouseManager warehouseManager;
    int nextItemId; // Для генерации уникальных ID товаров
public:
    Menu();
    void showLoginMenu();
    void showAdminMenu();
    void showSalesAgentMenu();
    void showDirectorMenu();
    void showAccountantMenu();
    void showWarehouseMenu();
};