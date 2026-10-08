#include <iostream>
using namespace std;

int main() {
    int a{}, b{};
    
    cin >> a >> b;

    int zbroj{a + b};
    double sredina{(a + b) / 2.0};
    bool usporedba{a < b};

    cout << "zzbroj: " << zbroj << endl;
    cout << "airtmeticka sredina: " << sredina << endl;
    cout << "a < b: " << boolalpha << usporedba << endl;

    return 0;
}