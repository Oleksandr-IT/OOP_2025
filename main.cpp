// main.cpp

#include "detal.h"
#include <vector>
#include <iomanip>
#include <locale>
#include <limits>

// !!! ВИКОРИСТАННЯ using namespace std !!!
using namespace std;

int main() {
    // Встановлення української локалі для виведення в консоль
    setlocale(LC_ALL, "uk_UA.UTF-8");

    int N;
    cout << "Введіть кількість деталей (N): ";
    while (!(cin >> N) || N <= 0) {
        cout << "Некоректна кількість (потрібне ціле число > 0). Введіть знову: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // 1. Введення масиву даних ZAKAZ
    vector<DETAL> ZAKAZ(N);
    cout << "\n*** ВВЕДЕННЯ ДАНИХ ZAKAZ ***" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "\nДеталь #" << i + 1 << " з " << N << endl;
        ZAKAZ[i].readData();
    }

    // 2. Введення дати для фільтрації
    cout << "\n*** ФІЛЬТРАЦІЯ ДАНИХ ***" << endl;
    cout << "Введіть дату, пізніше якої шукати деталі І сорту: " << endl;
    Date filterDate;
    filterDate.readFromConsole();
    
    // 3. Виведення відфільтрованих деталей
    cout << "\n\n*** РЕЗУЛЬТАТ: ДЕТАЛІ I СОРТУ, ВИГОТОВЛЕНІ ПІСЛЯ " 
              << filterDate.toString() << " ***" << endl;
    
    // Заголовок таблиці
    cout << left 
              << setw(15) << "Назва" 
              << setw(5) << "Сорт" 
              << setw(12) << "Дата виг." 
              << setw(10) << "Кількість" 
              << "Ціна" << endl;
    cout << string(50, '-') << endl;
    
    int count = 0;
    for (const auto& detal : ZAKAZ) {
        // Умова: Деталь I сорту І виготовлена пізніше заданої дати
        if (detal.getSort() == 1 && detal.isFabricatedLaterThan(filterDate)) {
            detal.displayData();
            count++;
        }
    }

    if (count == 0) {
        cout << "--> Жодної деталі, що відповідає критеріям, не знайдено." << endl;
    }

    return 0;
}