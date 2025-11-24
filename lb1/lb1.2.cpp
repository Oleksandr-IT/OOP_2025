#include <iostream>
#include <complex>
#include <cstdarg> // для роботи зі змінною кількістю параметрів

using namespace std;

double sub(double a, double b) {
    return a - b;
}

complex<double> sub(complex<double> a, complex<double> b) {
    return a - b;
}

int findMin(int count, ...) {
    va_list args;
    va_start(args, count);
    int minVal = va_arg(args, int);
    for (int i = 1; i < count; ++i) {
        int val = va_arg(args, int);
        if (val < minVal) minVal = val;
    }
    va_end(args);
    return minVal;
}

double maxfindMin(double dummy, int count, ...) {
    va_list args;
    va_start(args, count);
    double minVal = va_arg(args, double);
    for (int i = 1; i < count; ++i) {
        double val = va_arg(args, double);
        if (val < minVal) minVal = val;
    }
    va_end(args);
    return minVal;
}

int main() {
    cout << "=== Віднімання ===" << endl;
    double a = 6.5, b = 2.9;
    cout << "sub(6.5, 2.9) = " << sub(a, b) << endl;

    complex<double> c1(4, 6), c2(1, 2);
    cout << "sub((4+6i), (1+2i)) = " << sub(c1, c2) << endl;

    cout << "\n=== Мінімум серед чисел ===" << endl;
    cout << "min(int): " << findMin(3, 4, 7, 2) << endl;
    cout << "min(double): " << findMin(0.0, 4, 5.2, 3.1, 8.7, 2.4) << endl;

    return 0;
}
