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

// ����� ��� ������������
class User {
public:
    string login;
    string password;
    string role;
    User(string l, string p, string r) : login(l), password(p), role(r) {}
};

// ����� ��� ������
class Item {
public:
    int id; // ���������� ������������� ������
    string name;
    int quantity;
    double price; // ���� ������
    Item() : id(0), name(""), quantity(0), price(0.0) {} // ����������� �� ���������
    Item(int i, string n, int q, double p) : id(i), name(n), quantity(q), price(p) {}
};

// ����� ��� �������
class Sale {
public:
    int itemId; // ID ������
    string itemName;
    int quantity;
    double price; // ���� �� ������� �� ������ �������
    string store;
    time_t saleTime;
    Sale(int i, string n, int q, double p, string s) : itemId(i), itemName(n), quantity(q), price(p), store(s), saleTime(time(0)) {}
};

// ����� ��� ��������������
class Admin {
public:
    void addUser(vector<User>& users, int roleIndex, string login, string password);
    void removeUser(vector<User>& users, string login);
};

// ����� ��� ����������
class Accountant {
public:
    void createInvoice(const vector<Sale>& sales);
    void viewTaxReport(const vector<Sale>& sales);
    void sendDataToWarehouse(const vector<Sale>& sales);
};

// ����� ��� ���������
class Director {
public:
    void viewReports(const map<int, Item>& stock);
    void viewAgentActivity(const vector<Sale>& sales);
    void viewTaxReport(const vector<Sale>& sales); // ����� ����� ��� ��������� ������ �� �������
};

// ����� ��� ��������� ������
class SalesAgent {
public:
    void viewStock(const map<int, Item>& stock);
    void sellItem(vector<Sale>& sales, map<int, Item>& stock, int id, int qty, string store);
    void sendToAccounting(const vector<Sale>& sales);
    void viewSoldItemsCount(const vector<Sale>& sales);
};

// ����� ��� ����������� �������
class WarehouseManager {
public:
    void manageStock(const map<int, Item>& stock);
    void shipItem(map<int, Item>& stock, const vector<Sale>& sales);
    void addStock(map<int, Item>& stock, int id, string name, int qty, double price);
    void viewSoldItemsToday(const vector<Sale>& sales);
    void sendStockReport(const map<int, Item>& stock);
};

// ����� ��� ������
class Warehouse {
public:
    map<int, Item> stock; // �����: ID ������ -> ������ Item
    void displayStock() const;
};

// ����� ��� ����
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
    int nextItemId; // ��� ��������� ���������� ID �������
public:
    Menu();
    void showLoginMenu();
    void showAdminMenu();
    void showSalesAgentMenu();
    void showDirectorMenu();
    void showAccountantMenu();
    void showWarehouseMenu();
};