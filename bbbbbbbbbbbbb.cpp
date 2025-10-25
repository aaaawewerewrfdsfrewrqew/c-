#include <iostream>
using namespace std;

int main() {
    const int N1 = 10;
    int arr[N1] = { 5, 0, 3, 0, -2, 7, 0, 4, 0, 1 };

    cout << "Початковий масив: ";
    for (int i = 0; i < N1; i++) cout << arr[i] << " ";
    cout << endl;

    int index = 0;
    for (int i = 0; i < N1; i++) {
        if (arr[i] != 0) {
            arr[index] = arr[i];
            index++;
        }
    }

    for (int i = index; i < N1; i++) {
        arr[i] = -1;
    }

    cout << "Після стискання: ";
    for (int i = 0; i < N1; i++) cout << arr[i] << " ";
    cout << endl << endl;


    const int N2 = 5;
    int a[N2] = { 3, -1, 0, 7, -5 };
    int b[N2] = { 0, 2, -3, 0, 4 };
    int c[2 * N2];
    int pos = 0;

    cout << "Масив A: ";
    for (int i = 0; i < N2; i++) cout << a[i] << " ";
    cout << endl;

    cout << "Масив B: ";
    for (int i = 0; i < N2; i++) cout << b[i] << " ";
    cout << endl;

    for (int i = 0; i < N2; i++)
        if (a[i] > 0) c[pos++] = a[i];
    for (int i = 0; i < N2; i++)
        if (b[i] > 0) c[pos++] = b[i];

    for (int i = 0; i < N2; i++)
        if (a[i] == 0) c[pos++] = a[i];
    for (int i = 0; i < N2; i++)
        if (b[i] == 0) c[pos++] = b[i];

    for (int i = 0; i < N2; i++)
        if (a[i] < 0) c[pos++] = a[i];
    for (int i = 0; i < N2; i++)
        if (b[i] < 0) c[pos++] = b[i];

    cout << "об'єднаний масив: ";
    for (int i = 0; i < 2 * N2; i++) cout << c[i] << " ";
    cout << endl;

    return 0;
}
