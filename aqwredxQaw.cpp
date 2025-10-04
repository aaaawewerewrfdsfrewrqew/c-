#include <iostream>
using namespace std;

int main() {
    int width, height;
    char ch;

    cout << "Введіть ширину: ";
    cin >> width;
    cout << "Введіть висоту: ";
    cin >> height;
    cout << "Введіть символ: ";
    cin >> ch;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << ch;
        }
        cout << endl;
    }
    int color;

    cout << "Введіть ширину: ";
    cin >> width;
    cout << "Введіть висоту: ";
    cin >> height;
    cout << "Введіть символ: ";
    cin >> ch;

    cout << "Виберіть колір (номер):" << endl;
    cout << "1 - чорний" << endl;
    cout << "2 - червоний" << endl;
    cout << "3 - зелений" << endl;
    cout << "4 - жовтий" << endl;
    cout << "5 - синій" << endl;
    cout << "6 - пурпурний" << endl;
    cout << "7 - блакитний" << endl;
    cout << "8 - білий" << endl;
    cout << "Ваш вибір: ";
    cin >> color;

    switch (color) {
    case 1: cout << "\033[30m"; break;
    case 2: cout << "\033[31m"; break;
    case 3: cout << "\033[32m"; break;
    case 4: cout << "\033[33m"; break;
    case 5: cout << "\033[34m"; break;
    case 6: cout << "\033[35m"; break;
    case 7: cout << "\033[36m"; break;
    case 8: cout << "\033[37m"; break;
    default: cout << "\033[0m"; break;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                cout << ch;
            else
                cout << " ";
        }
        cout << endl;
    }

}
