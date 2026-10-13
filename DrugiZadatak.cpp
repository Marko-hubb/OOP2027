#include <iostream>
#include <string>
using namespace std;

int main() {
    int godrod{};
    string imePrezime{};

    cout << "godina";
    cin >> godrod;

    cin.ignore();

    cout << "ime i prezime: ";
    getline(cin, imePrezime);

    
    cout << "inicijali: " << imePrezime[0] << ".";

for (char znak : imePrezime) {
    cout << znak;
}

    
    int brojZnakova{};

    for (char znak : imePrezime) {
        if (znak != ' ') {
            brojZnakova++;
        }
    }

    cout << "\nbroj znakova bez razmaka: " << brojZnakova << endl;

    
    int godine{2026 - godrod};

    cout << "osoba ove godine ima: " << godine << " godina" << endl;

    return 0;
}
