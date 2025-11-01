#include <iostream>
using namespace std;

void sort_array(int arr[], int size, bool desc = false) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((desc && arr[i] < arr[j]) || (!desc && arr[i] > arr[j])) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertion_sort_half(int arr[], int size) {
    int half = size / 2;

    for (int i = 1; i < half; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = half + 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= half && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sort_between_negatives(int arr[], int size) {
    int left = -1, right = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            if (left == -1) left = i;
            right = i;
        }
    }

    if (left == -1 || right == -1 || left == right) return;
    for (int i = left + 1; i < right; i++) {
        for (int j = i + 1; j < right; j++) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int power_rec(int base, int exp) {
    if (exp == 0) return 1;
    return base * power_rec(base, exp - 1);
}

void print_stars(int n) {
    if (n == 0) return;
    cout << "*";
    print_stars(n - 1);
}

int sum_range_rec(int a, int b) {
    if (a > b) return 0;
    if (a == b) return a;
    return a + sum_range_rec(a + 1, b);
}

int main() {
    cout << "=== Завдання 1 ===" << endl;
    int arr1[10] = { 5, 2, 9, 1, 7, 6, 3, 8, 4, 0 };
    cout << "Початковий масив: ";
    print_array(arr1, 10);
    sort_array(arr1, 10);
    cout << "Сортування за зростанням: ";
    print_array(arr1, 10);
    sort_array(arr1, 10, true);
    cout << "Сортування за спаданням: ";
    print_array(arr1, 10);

    cout << "\n=== Завдання 2 ===" << endl;
    int arr2[10] = { 1, 7, 3, 9, 5, 6, 8, 2, 4, 0 };
    cout << "До сортування: ";
    print_array(arr2, 10);
    insertion_sort_half(arr2, 10);
    cout << "Після сортування половин: ";
    print_array(arr2, 10);

    cout << "\n=== Завдання 3 ===" << endl;
    int arr3[10] = { 5, -3, 7, 2, -1, 8, -2, 4, 9, -5 };
    cout << "До сортування: ";
    print_array(arr3, 10);
    sort_between_negatives(arr3, 10);
    cout << "Після сортування між від’ємними: ";
    print_array(arr3, 10);

    cout << "\n=== Рекурсія 1 ===" << endl;
    cout << "2^5 = " << power_rec(2, 5) << endl;

    cout << "\n=== Рекурсія 2 ===" << endl;
    cout << "Виведення 10 зірок: ";
    print_stars(10);
    cout << endl;

    cout << "\n=== Рекурсія 3 ===" << endl;
    int a = 3, b = 7;
    cout << "Сума чисел від " << a << " до " << b << " = " << sum_range_rec(a, b) << endl;

    return 0;
}
