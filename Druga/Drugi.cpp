#include <iostream>
using namespace std;

void my_sort(int arr[], int n, bool (*cmp)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cmp(arr[j + 1], arr[j])) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

inline bool ascending(int a, int b) {
    return a < b;
}

inline bool descending(int a, int b) {
    return a > b;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    my_sort(arr, n, ascending);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    my_sort(arr, n, descending);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}