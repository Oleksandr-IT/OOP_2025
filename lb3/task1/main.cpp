#include "train.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Функція для пошуку поїздів за критеріями
void findTrains(const vector<Train>& trains, const string& targetDestination, int departureHour, bool checkTime, bool checkGeneralSeats) {
    bool found = false;
    if (!trains.empty()) {
        trains[0].displayHeader();
    }
    
    // Перетворення рядка призначення для порівняння без урахування регістру (case-insensitive)
    string lowerTargetDest = targetDestination;
    transform(lowerTargetDest.begin(), lowerTargetDest.end(), lowerTargetDest.begin(), 
              [](unsigned char c){ return tolower(c); });

    for (const auto& train : trains) {
        // Отримання Destination для порівняння без урахування регістру
        string lowerTrainDest = train.getDestination();
        transform(lowerTrainDest.begin(), lowerTrainDest.end(), lowerTrainDest.begin(), 
                  [](unsigned char c){ return tolower(c); });

        // Основна умова: Пункт призначення повинен збігатися
        if (lowerTrainDest != lowerTargetDest) {
            continue;
        }

        // Додаткові умови фільтрації
        bool timeCondition = !checkTime || (train.getDepartureTime() > departureHour);
        bool seatsCondition = !checkGeneralSeats || train.hasGeneralSeats();

        if (timeCondition && seatsCondition) {
            train.displayData();
            found = true;
        }
    }

    if (!found) {
        cout << string(59, '-') << endl;
        cout << "--> Жодного поїзда за вказаними критеріями не знайдено." << endl;
    }
}


int main() {
    int N;
    cout << "Введіть кількість поїздів (N): ";
    while (!(cin >> N) || N <= 0) {
        cout << "Некоректна кількість. Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Створення масиву об'єктів (вектора) Train
    vector<Train> ZAKAZ(N); 
    
    cout << "\n*** ВВЕДЕННЯ ДАНИХ ПРО ПОЇЗДИ ***" << endl;
    for (int i = 0; i < N; ++i) {
        ZAKAZ[i].readData();
    }

    // --- Запити користувача для фільтрації ---

    string targetDest;
    cout << "\n\n*** ЗАПИТИ ***" << endl;
    cout << "Введіть пункт призначення для пошуку: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, targetDest);
    
    int filterHour;
    cout << "Введіть годину відправлення (ціле число 0-23): ";
    while (!(cin >> filterHour) || filterHour < 0 || filterHour > 23) {
        cout << "Некоректний час. Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // -----------------------------------------------------------------
    // а) Список поїздів, що прямують до заданого пункту призначення
    // -----------------------------------------------------------------
    cout << "\n\n--- а) Поїзди до пункту \"" << targetDest << "\" ---" << endl;
    findTrains(ZAKAZ, targetDest, 0, false, false);
    
    // -----------------------------------------------------------------
    // б) Список поїздів, що прямують до заданого пункту призначення 
    //    та відправляються після заданої години
    // -----------------------------------------------------------------
    cout << "\n\n--- б) Поїзди до \"" << targetDest << "\" після " << filterHour << ":00 год ---" << endl;
    findTrains(ZAKAZ, targetDest, filterHour, true, false);

    // -----------------------------------------------------------------
    // в) Список поїздів, що вирушають до заданого пункту призначення 
    //    та мають спільні місця
    // -----------------------------------------------------------------
    cout << "\n\n--- в) Поїзди до \"" << targetDest << "\" зі спільними місцями ---" << endl;
    findTrains(ZAKAZ, targetDest, 0, false, true);

    return 0;
}