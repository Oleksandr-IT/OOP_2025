#include <iostream>
#include <string>

using namespace std;

char cyclicLeftShift(char ch, int shift) {
    unsigned char byte = static_cast<unsigned char>(ch);
    shift %= 8; // обмеження до 8 бітів
    return static_cast<char>(((byte << shift) | (byte >> (8 - shift))) & 0xFF);
}

string encryptString(const string& input, int shift) {
    string result;
    for (char ch : input) {
        result += cyclicLeftShift(ch, shift);
    }
    return result;
}

int main() {
    string text;
    int shift;

    cout << "Введіть рядок: ";
    getline(cin, text);

    cout << "Введіть величину зсуву (0-7): ";
    cin >> shift;

    string encrypted = encryptString(text, shift);
    cout << "Зашифрований рядок: " << encrypted << endl;

    return 0;
}
