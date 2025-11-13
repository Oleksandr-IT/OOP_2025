#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    private:
        int hours;
        int minutes;
        int seconds;

    public:
        // Конструктор за замовчуванням
        Time() : hours(0), minutes(0), seconds(0) {}

        // Ввід часу з клавіатури
        void input() {
            cout << "Введіть години (0-23): ";
            cin >> hours;
            cout << "Введіть хвилини (0-59): ";
            cin >> minutes;
            cout << "Введіть секунди (0-59): ";
            cin >> seconds;

            // Перевірка коректності
            if (hours < 0 || hours > 23) hours = 0;
            if (minutes < 0 || minutes > 59) minutes = 0;
            if (seconds < 0 || seconds > 59) seconds = 0;
        }

        // Вивід часу на екран
        void display() const {
            cout << "Час: "
                << setw(2) << setfill('0') << hours << ":"
                << setw(2) << setfill('0') << minutes << ":"
                << setw(2) << setfill('0') << seconds << endl;
        }

        // Обчислення часу до кінця доби
        void timeToMidnight() const {
            int totalSeconds = 24 * 3600; // кількість секунд у добі
            int currentSeconds = hours * 3600 + minutes * 60 + seconds;
            int remaining = totalSeconds - currentSeconds;

            int h = remaining / 3600;
            int m = (remaining % 3600) / 60;
            int s = remaining % 60;

            cout << "До кінця доби залишилось: "
                << setw(2) << setfill('0') << h << ":"
                << setw(2) << setfill('0') << m << ":"
                << setw(2) << setfill('0') << s << endl;
        }
};

int main() {
    Time t;
    t.input();
    t.display();
    t.timeToMidnight();
    return 0;
}