#ifndef TEXT_PROCESSOR_H
#define TEXT_PROCESSOR_H

#include <string>
#include <vector>

using namespace std;

class TextSegment {
private:
    string content;         // Текст фрагмента
    string font;            // Название шрифта
    int size;               // Размер шрифта
    bool isBold;            // Флаг жирного начертания
    bool isItalic;          // Флаг курсива
    bool isUnderlined;      // Флаг подчеркивания

public:
    TextSegment(const string& content); // Конструктор
    void setFont(const string& font);   // Установка шрифта
    void setSize(int size);             // Установка размера
    void setBold(bool bold);            // Установка жирного начертания
    void setItalic(bool italic);        // Установка курсива
    void setUnderlined(bool underlined); // Установка подчеркивания
    string getContent() const;          // Получение текста
    string getFormattedText() const;    // Получение отформатированного текста
};

class Document {
private:
    vector<TextSegment*> segments; // Список текстовых фрагментов
    string name;                   // Имя документа

public:
    Document(const string& name);  // Конструктор
    ~Document();                   // Деструктор
    void addSegment(TextSegment* segment); // Добавление фрагмента
    void removeSegment(int index);        // Удаление фрагмента
    void formatSegment(int index, const string& font, int size, bool bold, bool italic, bool underlined); // Форматирование
    void display() const;                  // Отображение документа
    void save(const string& filename) const; // Сохранение в файл
    void load(const string& filename);      // Загрузка из файла
};

class Clipboard {
private:
    TextSegment* content; // Скопированный фрагмент

public:
    Clipboard();           // Конструктор
    ~Clipboard();          // Деструктор
    void copy(TextSegment* segment); // Копирование
    void cut(TextSegment* segment, Document* doc, int index); // Вырезание
    void paste(Document* doc, int index); // Вставка
};

class TextProcessor {
private:
    Document* document;    // Текущий документ
    Clipboard* clipboard;   // Буфер обмена

public:
    TextProcessor();       // Конструктор
    ~TextProcessor();      // Деструктор
    void createDocument(const string& name); // Создание документа
    void editText(const string& text, int index); // Редактирование текста
    void formatText(int index, const string& font, int size, bool bold, bool italic, bool underlined); // Форматирование
    void copyText(int index); // Копирование
    void cutText(int index);  // Вырезание
    void pasteText(int index); // Вставка
    void saveDocument(const string& filename); // Сохранение
    void loadDocument(const string& filename); // Загрузка
    void displayDocument() const; // Отображение
};

#endif