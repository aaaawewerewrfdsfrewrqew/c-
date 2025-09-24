#include <iostream>
using namespace std;

int main()
{
    int numba;
    cout << "введіть шестизначне число ->";
    cin >> numba;
    if (numba >= 100000 && numba <= 999999) {
        int d1 = numba / 100000;
        int d2 = (numba / 10000) % 10;
        int d3 = (numba / 1000) % 10;
        int d4 = (numba / 100) % 10;
        int d5 = (numba / 10) % 10;
        int d6 = numba % 10;

        int sumLeft = d1 + d2 + d3;
        int sumRight = d4 + d5 + d6;

        if (sumLeft == sumRight) {
            cout << "число є щасливим\n";
        }
        else {
            cout << "Число не є щасливим\n";
        }
    }
    else {
        cout << "число не є шестизначним";
    }

    int n;
    cout << "введіть чотиризначне число -> ";
    cin >> n;

    if (n < 1000 || n > 9999) {
        cout << "не чотиризначне число!\n";
    }

    int d1 = n / 1000;
    int d2 = (n / 100) % 10;
    int d3 = (n / 10) % 10;
    int d4 = n % 10;

    int newNumber = d2 * 1000 + d1 * 100 + d4 * 10 + d3;

    cout << "нове число " << newNumber << endl;

    int n1, n2, n3, n4, n5, n6, n7;
    cout << "Введіть 7 чисел: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7;
    int mx = n1;
    if (n2 > mx) mx = n2;
    if (n3 > mx) mx = n3;
    if (n4 > mx) mx = n4;
    if (n5 > mx) mx = n5;
    if (n6 > mx) mx = n6;
    if (n7 > mx) mx = n7;
    cout << "максимальне число = " << mx << endl;

    int ab, bc, w;
    cout << "Введіть відстань A-B, відстань B-C і вагу: ";
    cin >> ab >> bc >> w;
    int r = 0;
    if (w <= 500) r = 1;
    if (w > 500 && w <= 1000) r = 4;
    if (w > 1000 && w <= 1500) r = 7;
    if (w > 1500 && w <= 2000) r = 9;
    int need1 = ab * r, need2 = bc * r;
    int ok = 1;
    if (r == 0) ok = 0;
    if (need1 > 300) ok = 0;
    if (need2 > 300) ok = 0;
    if (ok == 0) cout << "політ неможливий" << endl;
    if (ok == 1) {
        int add = 0;
        if (need1 + need2 > 300) add = need1 + need2 - 300;
        cout << "мінімальна дозаправка = " << add << endl;
    }

    int d1, m1, y1, d2, m2, y2;
    cout << "Введіть першу дату (д м р): ";
    cin >> d1 >> m1 >> y1;
    cout << "Введіть другу дату (д м р): ";
    cin >> d2 >> m2 >> y2;

    int k1 = 0;
    int i = 1;
    while (i < y1) {
        int leap = 0;
        if (i % 400 == 0) leap = 1;
        else if (i % 100 == 0) leap = 0;
        else if (i % 4 == 0) leap = 1;
        if (leap == 1) k1 += 366; else k1 += 365;
        i++;
    }
    i = 1;
    while (i < m1) {
        int d = 31;
        if (i == 2) {
            int leap = 0;
            if (y1 % 400 == 0) leap = 1;
            else if (y1 % 100 == 0) leap = 0;
            else if (y1 % 4 == 0) leap = 1;
            if (leap == 1) d = 29; else d = 28;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11) d = 30;
        k1 += d;
        i++;
    }
    k1 += d1;

    int k2 = 0;
    i = 1;
    while (i < y2) {
        int leap = 0;
        if (i % 400 == 0) leap = 1;
        else if (i % 100 == 0) leap = 0;
        else if (i % 4 == 0) leap = 1;
        if (leap == 1) k2 += 366; else k2 += 365;
        i++;
    }
    i = 1;
    while (i < m2) {
        int d = 31;
        if (i == 2) {
            int leap = 0;
            if (y2 % 400 == 0) leap = 1;
            else if (y2 % 100 == 0) leap = 0;
            else if (y2 % 4 == 0) leap = 1;
            if (leap == 1) d = 29; else d = 28;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11) d = 30;
        k2 += d;
        i++;
    }
    k2 += d2;

    int diff = k1 - k2;
    if (diff < 0) diff = -diff;
    cout << "різниця днів = " << diff << endl;

    double p1, p2, p3;
    cout << "Введіть продажі 3 менеджерів: ";
    cin >> p1 >> p2 >> p3;
    double z1 = 200;
    if (p1 <= 500) z1 += p1 * 0.03;
    if (p1 > 500 && p1 <= 1000) z1 += p1 * 0.05;
    if (p1 > 1000) z1 += p1 * 0.08;
    double z2 = 200;
    if (p2 <= 500) z2 += p2 * 0.03;
    if (p2 > 500 && p2 <= 1000) z2 += p2 * 0.05;
    if (p2 > 1000) z2 += p2 * 0.08;
    double z3 = 200;
    if (p3 <= 500) z3 += p3 * 0.03;
    if (p3 > 500 && p3 <= 1000) z3 += p3 * 0.05;
    if (p3 > 1000) z3 += p3 * 0.08;

    if (z1 >= z2 && z1 >= z3) z1 += 200;
    if (z2 >= z1 && z2 >= z3) z2 += 200;
    if (z3 >= z1 && z3 >= z2) z3 += 200;

    cout << "зарплати менеджерів = " << z1 << ", " << z2 << ", " << z3 << endl;
}
