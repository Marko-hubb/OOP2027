#include <iostream>
#include <string>

using namespace std;

struct Student {
    string ime;
    string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void filter_students(Student s[], int n,
                     void (*action)(Student&),
                     bool (*cond)(const Student&)) {
    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

void ispisi(Student& s) {
    cout << s.ime << " " << s.jmbag << " " << s.godina << " "
         << s.ects << " " << s.prosjek << endl;
}

void povecaj_godinu(Student& s) {
    s.godina++;
}

int main() {
    Student s[] = {
        {"Ana Anic", "0016000001", 1, 30, 4.2},
        {"Ivan Ivic", "0016000002", 1, 0, 0.0},
        {"Marko Maric", "0016000003", 2, 48, 3.4},
        {"Petra Peric", "0016000004", 3, 120, 3.8},
        {"Luka Lukic", "0016000005", 2, 45, 3.5}
    };
    int n = sizeof(s) / sizeof(s[0]);

    cout << "prva godina, barem jedan ispit:" << endl;
    filter_students(s, n, ispisi, [](const Student& st) {
        return st.godina == 1 && st.ects > 0;
    });

    cout << "prosjek veci od 3.5:" << endl;
    filter_students(s, n, ispisi, [](const Student& st) {
        return st.prosjek > 3.5;
    });

    filter_students(s, n, povecaj_godinu, [](const Student& st) {
        return st.ects >= 45;
    });

    cout << "posli povecanja godine:" << endl;
    filter_students(s, n, ispisi, [](const Student&) {
        return true;
    });

    return 0;
}