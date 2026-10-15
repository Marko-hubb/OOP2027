#include <iostream>
using namespace std;

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cmp(arr[j + 1], arr[j])) {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

inline bool ascending_int(int a, int b) {
    return a < b;
}

template <typename T>
inline bool ascending(T a, T b) {
    return a < b;
}

template <typename T>
inline bool descending(T a, T b) {
    return a > b;
}

template <typename T>
void print(T arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    double d[] = {3.5, 1.2, 9.9, 0.4};
    int nd = sizeof(d) / sizeof(d[0]);

    int a[] = {5, 2, 9, 1, 7, 3};
    int na = sizeof(a) / sizeof(a[0]);
    my_sort(a, na, ascending<int>);
    print(a, na);
    my_sort(a, na, descending<int>);
    print(a, na);

    my_sort(d, nd, ascending<double>);
    print(d, nd);
    my_sort(d, nd, descending<double>);
    print(d, nd);

    char c[] = {'k', 'a', 'z', 'b', 'm'};
    int nc = sizeof(c) / sizeof(c[0]);
    my_sort(c, nc, ascending<char>);
    print(c, nc);
    my_sort(c, nc, descending<char>);
    print(c, nc);

    return 0;
}