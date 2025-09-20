#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "число ";
    cin >> a;
    if (a % 2 == 0) cout << "рарне" << endl;
    else cout << "не парне" << endl;

    cout << "введіть два числа ";
    cin >> a >> b;
    if (a < b) cout << a << endl;
    else cout << b << endl;

    cout << "введіть число ";
    cin >> a;
    if (a > 0) cout << "додатнє" << endl;
    else if (a < 0) cout << "від'ємне" << endl;
    else cout << "0" << endl;

    cout << "введіть два числа ";
    cin >> a >> b;
    if (a == b) cout << " рівні" << endl;
    else if (a < b) cout << a << " " << b << endl;
    else cout << b << " " << a << endl;

    int o1, o2, o3, o4, o5;
    cout << "введіть 5 оцінок ";
    cin >> o1 >> o2 >> o3 >> o4 >> o5;
    double avg = (o1 + o2 + o3 + o4 + o5) / 5.0;
    if (avg >= 4) cout << "допущений" << endl;
    else cout << "не допущений" << endl;

    cout << "число ";
    cin >> a;
    if (a % 2 == 0) cout << a * 3 << endl;
    else cout << a / 2.0 << endl;

    double x, y;
    char op;
    cout << "введіть два числа ";
    cin >> x >> y;
    cout << "оберіть дію (+ - * /): ";
    cin >> op;
    if (op == '+') cout << x + y << endl;
    else if (op == '-') cout << x - y << endl;
    else if (op == '*') cout << x * y << endl;
    else if (op == '/') {
        if (y != 0) cout << x / y << endl;
        else cout << "не можна ділити на нуль" << endl;
    }

    return 0;
}
