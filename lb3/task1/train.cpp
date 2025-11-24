#include "train.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

Train::Train() 
    : destination(""), trainNumber(0), departureTime(0), totalSeats(0), cupeSeats(0), platskartSeats(0) {}

Train::Train(const string& dest, int number, int time, int total, int cupe, int plats) 
    : destination(dest), trainNumber(number), departureTime(time), totalSeats(total), cupeSeats(cupe), platskartSeats(plats) {}

// --- Реалізація методу введення даних ---
void Train::readData() {
    cout << "\n--- Введення даних для нового поїзда ---" << endl;
    cout << "Пункт призначення: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера перед getline
    getline(cin, destination);

    cout << "Номер поїзда (ціле число): ";
    while (!(cin >> trainNumber) || trainNumber <= 0) {
        cout << "Некоректний номер. Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Час відправлення (година 0-23): ";
    while (!(cin >> departureTime) || departureTime < 0 || departureTime > 23) {
        cout << "Некоректний час. Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Загальне число місць: ";
    while (!(cin >> totalSeats) || totalSeats < 0) {
        cout << "Некоректна кількість. Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Купейних місць: ";
    while (!(cin >> cupeSeats) || cupeSeats < 0 || cupeSeats > totalSeats) {
        cout << "Некоректна кількість (не може перевищувати загальну). Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Плацкартних місць: ";
    while (!(cin >> platskartSeats) || platskartSeats < 0 || (platskartSeats + cupeSeats) > totalSeats) {
        cout << "Некоректна кількість (сума купе і плацкарту не може перевищувати загальну). Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// --- Реалізація методу виведення заголовка таблиці ---
void Train::displayHeader() const {
    cout << left 
         << setw(5) << "#"
         << setw(20) << "Пункт призначення"
         << setw(8) << "Час"
         << setw(10) << "Загальні"
         << setw(8) << "Купе"
         << setw(8) << "Плац."
         << endl;
    cout << string(59, '-') << endl;
}

// --- Реалізація методу виведення даних ---
void Train::displayData() const {
    cout << left 
         << setw(5) << trainNumber
         << setw(20) << destination
         << setw(2) << setfill('0') << departureTime << setfill(' ') << " год"
         << setw(10) << totalSeats
         << setw(8) << cupeSeats
         << setw(8) << platskartSeats
         << endl;
}