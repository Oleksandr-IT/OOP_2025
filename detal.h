// detal.h

#ifndef DETAL_H
#define DETAL_H

#include <string>
#include <iostream>

// Використання директиви using namespace std в заголовкових файлах
// загалом не рекомендується у великих проектах, але для виконання
// Вашого запиту я додам її лише у *.cpp файли, щоб не забруднювати
// глобальний простір імен у файлах, що інклудять detal.h.
// Для оголошення класів тут std:: залишимо, це стандартна практика.

// --- Допоміжний клас для представлення дати ---
class Date {
private:
    int year;
    int month;
    int day;

public:
    // Конструктори
    Date();
    Date(const std::string& dateStr);

    // Гетери
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    // Методи
    void readFromConsole();
    std::string toString() const;
    bool isLaterThan(const Date& other) const;
    bool fromString(const std::string& dateStr);
};

// --- Клас DETAL ---
class DETAL {
private:
    std::string Name;
    int Sort;
    Date FabricationDate;
    int Quant;
    double Cost;

public:
    // Конструктор за замовчуванням
    DETAL();

    // --- Гетери (для доступу до полів) ---
    std::string getName() const { return Name; }
    int getSort() const { return Sort; }
    Date getDate() const { return FabricationDate; }
    int getQuant() const { return Quant; }
    double getCost() const { return Cost; }
    
    // --- Основні методи класу ---
    void readData();      // Зчитування всіх даних деталі
    void displayData() const; // Виведення даних деталі
    
    // Метод для перевірки критерію дати
    bool isFabricatedLaterThan(const Date& otherDate) const;
};

#endif // DETAL_H