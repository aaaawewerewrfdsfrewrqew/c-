#include <iostream>
using namespace std;

int main() {

        cout << "назва : \"Кобзар\"" << endl;
        cout << "Автор : Тарас Шевченко" << endl;
        cout << "Видавництво: київ" << endl;
        cout << "сторінок : 250" << endl << endl;

        cout << "Реве та стогне дніпр широкий," << endl;
        cout << "Сердитий вітер завива," << endl;
        cout << "Додолу верби гне високі," << endl;
        cout << "Горами хвилю підійма." << endl << endl;

    cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;

    cout << (char)186 << " Пори року" << "                                   " << (char)186 << endl;

    cout << (char)204 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)203 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)203 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)203 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)185 << endl;

    cout << (char)186 << " Зима   " << (char)186
        << " Весна     " << (char)186
        << " Літо      " << (char)186
        << " Осінь   " << (char)186 << endl;

    cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)202 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)202 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)202 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)205 << (char)205
        << (char)205 << (char)205 << (char)205 << (char)188 << endl << endl;

    int rik;
    cout << "введи рік: ";
    cin >> rik;
    int dni = 365 + (rik % 4 == 0 && rik % 100 != 0 || rik % 400 == 0);
    cout << "у " << rik << " році = " << dni << " днів" << endl << endl;

    int grn, kop;
    cout << "введи гривні: ";
    cin >> grn;
    cout << "введи копійки: ";
    cin >> kop;
    grn += kop / 100;
    kop = kop % 100;
    cout << grn << " грн " << kop << " коп" << endl << endl;

    double a, b, c;
    cout << "довжина (см) -> ";
    cin >> a;
    cout << "ширина (см) -> ";
    cin >> b;
    cout << "висота (см) -> ";
    cin >> c;
    cout << "об’єм: " << a * b * c << " куб. см." << endl << endl;

    double mashtab, vidstan;
    cout << "масштаб карти (км в 1 см) ";
    cin >> mashtab;
    cout << "відстань між точками (см) ";
    cin >> vidstan;
    cout << "відстань між населеними пунктами " << mashtab * vidstan << " кілометрів." << endl << endl;

    double r;
    cout << "радіус -> ";
    cin >> r;
    double pi = 3.14159;
    double V = 4.0 / 3.0 * pi * r * r * r;
    cout << "об’єм кулі: " << V << endl;

}
