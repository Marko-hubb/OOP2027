#include <iostream>
using namespace std;

inline double add(double a, double b)      { return a + b; }
inline double subtract(double a, double b) { return a - b; }
inline double multiply(double a, double b) { return a * b; }
inline double divide(double a, double b)   { return a / b; }

int main() {
    double (*operacije[4])(double, double) = { add, subtract, multiply, divide };

    double x, y;
    int op;

    cout << "unesite dva broja: ";
    cin >> x >> y;

    cout << "unesit redni broj operacije : ";
    cin >> op;

    if (op < 0 || op > 3) {
        cout << "Neispravan redni broj operacije." << endl;
        return 1;
    }

    if (op == 3 && y == 0) {
        cout << "nemoze se s nulomm" << endl;
        return 1;
    }

    cout << "rezz: " << operacije[op](x, y) << endl;

    return 0;
}