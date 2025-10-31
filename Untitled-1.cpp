#include <iostream>
using namespace std;

double power(double base, int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

int sum_range(int a, int b) {
    if (a > b) {
        int t = a; a = b; b = t;
    }
    int sum = 0;
    for (int i = a; i <= b; i++)
        sum += i;
    return sum;
}

bool is_perfect(int n) {
    int s = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0)
            s += i;
    return s == n;
}

void perfect_numbers_in_range(int start, int end) {
    cout << "Досконалі числа від " << start << " до " << end << ": ";
    for (int n = start; n <= end; n++)
        if (is_perfect(n))
            cout << n << " ";
    cout << endl;
}

void show_card(char rank1, char rank2, char suit) {
    char symbol;
    if (suit == 'H') symbol = char(3);   // ♥
    else if (suit == 'D') symbol = char(4); // ♦
    else if (suit == 'C') symbol = char(5); // ♣
    else symbol = char(6); // ♠

    if (rank2 == ' ')
        cout << rank1 << symbol << endl;
    else
        cout << rank1 << rank2 << symbol << endl;
}

bool is_lucky(int num) {
    int a1 = num / 100000 % 10;
    int a2 = num / 10000 % 10;
    int a3 = num / 1000 % 10;
    int a4 = num / 100 % 10;
    int a5 = num / 10 % 10;
    int a6 = num % 10;
    return (a1 + a2 + a3) == (a4 + a5 + a6);
}

int linear_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binary_search(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binary_to_decimal(int bin) {
    int dec = 0, base = 1, rem;
    while (bin > 0) {
        rem = bin % 10;
        dec += rem * base;
        base *= 2;
        bin /= 10;
    }
    return dec;
}

int main() {
    cout << "2 у степені 3 = " << power(2, 3) << endl;

    cout << "Сума чисел від 3 до 7 = " << sum_range(3, 7) << endl;

    perfect_numbers_in_range(1, 10000);

    cout << "Карти:" << endl;
    show_card('A', ' ', 'H');
    show_card('1', '0', 'S');

    cout << "123321 — щасливе? " << (is_lucky(123321) ? "Так" : "Ні") << endl;
    cout << "111222 — щасливе? " << (is_lucky(111222) ? "Так" : "Ні") << endl;

    int arr1[5] = {1, 3, 5, 7, 9};
    cout << "Лінійний пошук 7 у [1,3,5,7,9] => " << linear_search(arr1, 5, 7) << endl;

    int arr2[6] = {1, 3, 5, 7, 9, 11};
    cout << "Бінарний пошук 9 у [1,3,5,7,9,11] => " << binary_search(arr2, 6, 9) << endl;

    cout << "Двійкове число 1010 у десятковій системі = " << binary_to_decimal(1010) << endl;

    return 0;
}