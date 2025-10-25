#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isInteger(const string &s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-') {
        if (s.size() == 1) return false;
        i = 1;
    }
    for (; i < s.size(); ++i)
        if (!isdigit(static_cast<unsigned char>(s[i]))) return false;
    return true;
}

bool isFloat(const string &s) {
    if (s.empty()) return false;
    size_t i = 0;
    bool foundDot = false;
    if (s[0] == '+' || s[0] == '-') {
        if (s.size() == 1) return false;
        i = 1;
    }
    for (; i < s.size(); ++i) {
        char c = s[i];
        if (c == '.') {
            if (foundDot) return false; // more than one dot -> not a float
            foundDot = true;
            // dot cannot be the last character
            if (i == s.size() - 1) return false;
        } else if (!isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return foundDot; // true only if it contains a dot and otherwise digits
}

int main() {
    cout << "Hello developer community!" << endl;
    cout << "Integer value: " << 42 << endl;
    cout << "Float value: " << 3.14 << endl;
    cout << "String value: " << "C++ Programming" << endl;

    int a = 10;
    int b = 20;
    int sum = a + b;
    cout << "The sum of " << a << " and " << b << " is: " << sum << endl;

    cout << "\nEnter any value: ";
    string input;
    if (!getline(cin, input)) {
        cerr << "Input error." << endl;
        return 1;
    }

    if (isInteger(input)) {
        cout << "You entered an integer." << endl;
    } else if (isFloat(input)) {
        cout << "You entered a float." << endl;
    } else {
        // If it contains letters, treat as string; else unknown
        bool hasAlpha = false;
        for (char c : input) {
            if (isalpha(static_cast<unsigned char>(c))) { hasAlpha = true; break; }
        }
        if (hasAlpha) cout << "You entered a string." << endl;
        else cout << "Unknown type." << endl;
    }

    return 0;
}