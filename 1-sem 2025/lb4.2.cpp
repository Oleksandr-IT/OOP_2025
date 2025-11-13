#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Нормалізація часу (щоб не виходив за межі)
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        } else if (seconds < 0) {
            minutes -= (abs(seconds) / 60 + 1);
            seconds = 60 - abs(seconds) % 60;
        }

        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        } else if (minutes < 0) {
            hours -= (abs(minutes) / 60 + 1);
            minutes = 60 - abs(minutes) % 60;
        }

        if (hours >= 24) hours %= 24;
        if (hours < 0) hours = (24 + hours % 24) % 24;
    }

public:
    // Конструктор за замовчуванням
    Time() : hours(0), minutes(0), seconds(0) {}

    // Перевантажений конструктор
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Деструктор
    ~Time() {
        // Можна додати повідомлення для демонстрації
        // cout << "Об'єкт Time знищено\n";
    }

    // Ввід часу
    void input() {
        cout << "Введіть години (0-23): ";
        cin >> hours;
        cout << "Введіть хвилини (0-59): ";
        cin >> minutes;
        cout << "Введіть секунди (0-59): ";
        cin >> seconds;
        normalize();
    }

    // Вивід часу
    void display() const {
        cout << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }

    // Час до кінця доби
    void timeToMidnight() const {
        int totalSeconds = 24 * 3600;
        int currentSeconds = hours * 3600 + minutes * 60 + seconds;
        int remaining = totalSeconds - currentSeconds;

        int h = remaining / 3600;
        int m = (remaining % 3600) / 60;
        int s = remaining % 60;

        cout << "До кінця доби: "
             << setw(2) << setfill('0') << h << ":"
             << setw(2) << setfill('0') << m << ":"
             << setw(2) << setfill('0') << s << endl;
    }

    // Оператор +
    Time operator+(const Time& t) const {
        Time result(hours + t.hours, minutes + t.minutes, seconds + t.seconds);
        result.normalize();
        return result;
    }

    // Оператор -
    Time operator-(const Time& t) const {
        Time result(hours - t.hours, minutes - t.minutes, seconds - t.seconds);
        result.normalize();
        return result;
    }

    // Префіксний ++ (хвилини +1)
    Time& operator++() {
        minutes++;
        normalize();
        return *this;
    }

    // Постфіксний ++ (секунди +1)
    Time operator++(int) {
        Time temp = *this;
        seconds++;
        normalize();
        return temp;
    }

    // Префіксний -- (хвилини -1)
    Time& operator--() {
        minutes--;
        normalize();
        return *this;
    }

    // Постфіксний -- (секунди -1)
    Time operator--(int) {
        Time temp = *this;
        seconds--;
        normalize();
        return temp;
    }

    // Оператори порівняння
    bool operator<(const Time& t) const {
        return (hours * 3600 + minutes * 60 + seconds) <
               (t.hours * 3600 + t.minutes * 60 + t.seconds);
    }

    bool operator==(const Time& t) const {
        return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
    }

    bool operator>(const Time& t) const {
        return (hours * 3600 + minutes * 60 + seconds) >
               (t.hours * 3600 + t.minutes * 60 + t.seconds);
    }
};

// Демонстрація роботи
int main() {
    Time t1(12, 30, 45);
    Time t2;
    t2.input();

    cout << "\nЧас 1: "; t1.display();
    cout << "Час 2: "; t2.display();

    cout << "\nСума: "; (t1 + t2).display();
    cout << "Різниця: "; (t1 - t2).display();

    cout << "\nПрефіксний ++ (хвилини +1): "; (++t1).display();
    cout << "Постфіксний ++ (секунди +1): "; (t1++).display();
    cout << "Після постфіксного ++: "; t1.display();

    cout << "\nПрефіксний -- (хвилини -1): "; (--t1).display();
    cout << "Постфіксний -- (секунди -1): "; (t1--).display();
    cout << "Після постфіксного --: "; t1.display();

    cout << "\nПорівняння:\n";
    cout << "t1 < t2 ? " << (t1 < t2 ? "Так" : "Ні") << endl;
    cout << "t1 == t2 ? " << (t1 == t2 ? "Так" : "Ні") << endl;
    cout << "t1 > t2 ? " << (t1 > t2 ? "Так" : "Ні") << endl;

    cout << "\n"; t1.timeToMidnight();

    return 0;
}