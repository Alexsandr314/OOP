#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
};

class Operator : public Token {
private:
    char oper;
public:
    Operator(char c) : oper(c) {}
    float getNumber() override { return 0.0; }
    char getOperator() override { return oper; }
};

class Number : public Token {
private:
    float fnum;
public:
    Number(float f) : fnum(f) {}
    float getNumber() override { return fnum; }
    char getOperator() override { return '\0'; }
};

class Stack {
private:
    Token* arr[100];
    int top;
public:
    Stack() : top(-1) {}
    void push(Token* t) {
        if (top < 99) arr[++top] = t;
    }
    Token* pop() {
        if (top >= 0) return arr[top--];
        return nullptr;
    }
    bool isEmpty() const { return top == -1; }
    ~Stack() {
        while (!isEmpty()) delete pop();
    }
};

int main() {
    Stack s;
    string input;
    cout << "Введите выражение (например, 3.14159 / 2.0 + 75.25 * 3.333): ";
    getline(cin, input);

    string num;
    for (size_t i = 0; i <= input.length(); i++) {
        if (isdigit(input[i]) || input[i] == '.') {
            num += input[i];
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            if (!num.empty()) {
                s.push(new Number(stof(num)));
                num.clear();
            }
            s.push(new Operator(input[i]));
        }
        else if (isspace(input[i]) || input[i] == '\0') {
            if (!num.empty()) {
                s.push(new Number(stof(num)));
                num.clear();
            }
        }
    }

    Stack temp;
    while (!s.isEmpty()) temp.push(s.pop());

    Stack numbers;
    while (!temp.isEmpty()) {
        Token* t = temp.pop();
        if (t->getNumber() != 0.0) {
            numbers.push(t);
        }
        else {
            Number* n2 = (Number*)numbers.pop();
            Number* n1 = (Number*)numbers.pop();
            float result = 0.0;
            switch (t->getOperator()) {
            case '+': result = n1->getNumber() + n2->getNumber(); break;
            case '-': result = n1->getNumber() - n2->getNumber(); break;
            case '*': result = n1->getNumber() * n2->getNumber(); break;
            case '/': result = n1->getNumber() / n2->getNumber(); break;
            }
            numbers.push(new Number(result));
            delete n1; delete n2; delete t;
        }
    }

    Number* result = (Number*)numbers.pop();
    cout << "Результат: " << result->getNumber() << endl;
    delete result;

    return 0;
}