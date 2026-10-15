#include <iostream>
#include <algorithm>
using namespace std;

void my_transform(int arr[], int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

int twice(int x) {
    return 2 * x;
}

void ispis(const int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Pocetni niz:        ";
    ispis(arr, n);

    my_transform(arr, n, twice);
    cout << "Nakon twice:        ";
    ispis(arr, n);

    my_transform(arr, n, [](int x) {
        if (x % 2 == 0) return x / 2;
        return x * 2;
    });
    cout << "pisli lambde:       ";
    ispis(arr, n);

    int suma = 0;
    long long produkt = 1;
    for_each(arr, arr + n, [&](int x) {
        suma += x;
        produkt *= x;
    });
    cout << "Suma = " << suma << ", prrodukt = " << produkt << endl;

    int prag = 5;
    int s = 0;
    for_each(arr, arr + n, [prag, &s](int x) {
        if (x > prag) s += x;
    });
    cout << "suma clanova vecih od " << prag << " = " << s << endl;

    return 0;
}