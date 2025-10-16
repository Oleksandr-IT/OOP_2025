#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    double a[n];
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout<<"Заданий масив: ";
    for (int i=0; i<n; ++i) {
        cout << a[i] << " ";
    }
    cout<<"\n";

    // 1. Визначення мінімального елемента масиву
    double min=a[0];
    for (int i=0; i<n; ++i) {
        if(min>a[i]) min=a[i];
    }

    // 2. Сума елементів між першим і останнім позитивними
    int firstPos = -1, lastPos = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            if (firstPos == -1) firstPos = i;
            lastPos = i;
        }
    }

    double sumBetween = 0;
    if (firstPos != -1 && lastPos != -1 && firstPos < lastPos) {
        for (int i = firstPos + 1; i < lastPos; ++i) {
            sumBetween += a[i];
        }
    }

    // 3. Перетворення масиву: нулі спочатку, потім інші
    vector<double> transformed;
    for (double x : a) {
        if (x == 0) transformed.push_back(x);
    }
    for (double x : a) {
        if (x != 0) transformed.push_back(x);
    }

    cout << "Мінімальний елемент масиву: " << min << "\n";
    cout << "Сума елементів між першим і останнім позитивними: " << sumBetween << "\n";
    cout << "Перетворений масив:\n";
    for (double x : transformed) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
