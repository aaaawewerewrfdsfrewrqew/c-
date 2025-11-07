#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void sortArray(int arr[], int size, bool descending = false) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            bool condition = descending ? arr[j] < arr[j + 1] : arr[j] > arr[j + 1];
            if (condition) swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSort(int arr[], int start, int end, bool descending) {
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && (descending ? arr[j] < key : arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortBetweenNegatives(int arr[], int size) {
    int left = -1, right = -1;
    for (int i = 0; i < size; i++)
        if (arr[i] < 0) { left = i; break; }
    for (int i = size - 1; i >= 0; i--)
        if (arr[i] < 0) { right = i; break; }
    if (left != -1 && right != -1 && right > left + 1)
        sort(arr + left + 1, arr + right);
}

double power(double base, int exp) {
    if (exp == 0) return 1;
    if (exp > 0) return base * power(base, exp - 1);
    else return 1 / power(base, -exp);
}

void printStars(int n) {
    if (n == 0) return;
    cout << "*";
    printStars(n - 1);
}

int sumRange(int a, int b) {
    if (a > b) return 0;
    if (a == b) return a;
    return a + sumRange(a + 1, b);
}

int findMinSumIndex(int arr[], int start, int end, int size, int window) {
    if (start + window > size) return end;
    int currentSum = 0, minSum = 0;
    for (int i = start; i < start + window; i++) currentSum += arr[i];
    for (int i = end; i < end + window; i++) minSum += arr[i];
    if (currentSum < minSum) end = start;
    return findMinSumIndex(arr, start + 1, end, size, window);
}

int maxValue(int a, int b) { return (a > b) ? a : b; }
int maxValue(int a, int b, int c) { return max(max(a, b), c); }
int maxValue(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}
int maxValue(int arr[][3], int rows, int cols) {
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] > maxVal) maxVal = arr[i][j];
    return maxVal;
}
int maxValue(int arr[][3][3], int x, int y, int z) {
    int maxVal = arr[0][0][0];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                if (arr[i][j][k] > maxVal) maxVal = arr[i][j][k];
    return maxVal;
}

int main() {
    srand(time(0));

    int arr1[10] = { 5, -3, 9, 0, 2, -8, 4, 7, -1, 6 };
    sortArray(arr1, 10, true);
    cout << "Сортування за спаданням: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    sortArray(arr1, 10, false);
    cout << "Сортування за зростанням: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n\n";

    int arr2[10] = { 4, -2, 6, 1, 9, 3, -5, 0, 8, 7 };
    insertionSort(arr2, 0, 4, true);
    insertionSort(arr2, 5, 9, false);
    cout << "Перша половина ↓, друга ↑: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    int arr3[10] = { 5, -3, 9, 0, -2, 8, -1, 6, -4, 7 };
    sortBetweenNegatives(arr3, 10);
    cout << "Після сортування між крайніми від’ємними: ";
    for (int x : arr3) cout << x << " ";
    cout << "\n\n";

    cout << "2^5 = " << power(2, 5) << "\n\n";

    cout << "Зірки: ";
    printStars(10);
    cout << "\n\n";

    cout << "Сума від 3 до 7 = " << sumRange(3, 7) << "\n\n";

    int arr4[100];
    for (int i = 0; i < 100; i++) arr4[i] = rand() % 41 - 20;
    cout << "Індекс мінімальної суми 10 елементів: "
        << findMinSumIndex(arr4, 0, 0, 100, 10) << "\n\n";

    int a1[5] = { 3, 7, 1, 9, 2 };
    int a2[2][3] = { {1, 5, 3}, {9, 2, 8} };
    int a3[2][2][3] = { {{1, 2, 3}, {4, 5, 6}}, {{7, 0, 9}, {5, 6, 8}} };

    cout << "max(3, 9) = " << maxValue(3, 9) << endl;
    cout << "max(3, 9, 5) = " << maxValue(3, 9, 5) << endl;
    cout << "max(масив 1D) = " << maxValue(a1, 5) << endl;
    cout << "max(масив 2D) = " << maxValue(a2, 2, 3) << endl;
    int maxValue(int arr[][2][3], int x, int y, int z) {
        int maxVal = arr[0][0][0];
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                for (int k = 0; k < z; k++)
                    if (arr[i][j][k] > maxVal) maxVal = arr[i][j][k];
        return maxVal;
    }
    cout << "max(масив 3D) = " << maxValue(a3, 2, 2, 3) << endl;

    return 0;
}