#include <iostream>
#include <cstdlib>
using namespace std;

int& find_max(int arr[], int n) {
    int najveci{0};

    for (int i{1}; i < n; i++) {
        if (arr[i] > arr[najveci]) {
            najveci = i;
        }
    }

    return arr[najveci];
}

int main() {
    int numbers[] = {4, -7, 12, 0, 9, -3};
    int n{6};

   
    cout << "pocetni : ";
    for (int broj : numbers) {
        cout << broj << " ";
    }

    cout << endl;

    
    for (int& broj : numbers) {
        if (broj < 0) {
            broj = abs(broj);
        }
    }

    cout << "niz posli apsolutnih vrijednosti: ";
    for (int broj : numbers) {
        cout << broj << " ";
    }

    cout << endl;

   
    find_max(numbers, n) = 0;

    cout << "niz posli postavljanja najveceg elementa na 0: ";
    for (int broj : numbers) {
        cout << broj << " ";
    }

    cout << endl;

    return 0;
}