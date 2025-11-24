// detal.cpp

#include "detal.h"
#include <sstream>
#include <iomanip>
#include <limits> 

// !!! ВИКОРИСТАННЯ using namespace std !!!
using namespace std;

// =========================================================
//                  РЕАЛІЗАЦІЯ КЛАСУ DATE
// =========================================================

// Конструктор за замовчуванням
Date::Date() : year(0), month(0), day(0) {}

// Конструктор з рядка (використовує fromString)
Date::Date(const string& dateStr) {
    if (!fromString(dateStr)) {
        year = month = day = 0;
    }
}

// Зчитування дати з консолі
void Date::readFromConsole() {
    string dateStr;
    bool valid = false;
    while (!valid) {
        cout << "  Введіть дату у форматі РРРР-ММ-ДД: ";
        cin >> dateStr;
        valid = fromString(dateStr);
        if (!valid) {
            cout << "  Невірний формат дати. Спробуйте ще раз." << endl;
        }
    }
}

// Перетворення рядка "YYYY-MM-DD" на поля класу
bool Date::fromString(const string& dateStr) {
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
        return false;
    }
    try {
        year = stoi(dateStr.substr(0, 4));
        month = stoi(dateStr.substr(5, 2));
        day = stoi(dateStr.substr(8, 2));
        // Базова перевірка діапазонів
        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900) {
            return false;
        }
        return true;
    } catch (const exception& e) {
        return false;
    }
}

// Перетворення дати на рядок
string Date::toString() const {
    stringstream ss;
    ss << setfill('0') << setw(4) << year << "-"
       << setfill('0') << setw(2) << month << "-"
       << setfill('0') << setw(2) << day;
    return ss.str();
}

// Порівняння: чи є поточна дата пізнішою за іншу дату
bool Date::isLaterThan(const Date& other) const {
    if (year > other.year) return true;
    if (year < other.year) return false;
    if (month > other.month) return true;
    if (month < other.month) return false;
    return day > other.day;
}


// =========================================================
//                 РЕАЛІЗАЦІЯ КЛАСУ DETAL
// =========================================================

// Конструктор за замовчуванням
DETAL::DETAL() : Name(""), Sort(0), Quant(0), Cost(0.0) {}

// Метод для зчитування даних деталі з клавіатури
void DETAL::readData() {
    cout << "\n--- Введення даних для нової деталі ---" << endl;
    cout << "Назва деталі (Name): ";
    cin >> Name;
    
    cout << "Сорт виробу (Sort): ";
    while (!(cin >> Sort) || Sort < 1) {
        cout << "Некоректний сорт (потрібне ціле число >= 1). Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Дата виготовлення (Date):" << endl;
    FabricationDate.readFromConsole();

    cout << "Кількість (Quant): ";
    while (!(cin >> Quant) || Quant < 1) {
        cout << "Некоректна кількість (потрібне ціле число >= 1). Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ціна деталі (Cost): ";
    while (!(cin >> Cost) || Cost <= 0) {
        cout << "Некоректна ціна (потрібне число > 0). Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Метод для виведення даних деталі на екран
void DETAL::displayData() const {
    cout << left 
              << setw(15) << Name
              << setw(5) << Sort
              << setw(12) << FabricationDate.toString()
              << setw(10) << Quant
              << fixed << setprecision(2) << Cost 
              << endl;
}

// Метод для перевірки, чи деталь виготовлена пізніше заданої дати
bool DETAL::isFabricatedLaterThan(const Date& otherDate) const {
    return FabricationDate.isLaterThan(otherDate);
}