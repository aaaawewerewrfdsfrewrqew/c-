#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\nвибір фігур:\n";
        cout << "1\n";
        cout << "2\n";
        cout << "3\n";
        cout << "4 \n";
        cout << "5\n";
        cout << "6\n";
        cout << "7\n";
        cout << "8\n";
        cout << "9\n";
        cout << "10\n";
        cout << "0 - вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "*****\n";
            cout << "**** \n";
            cout << "***  \n";
            cout << "**   \n";
            cout << "*    \n";
            break;

        case 2:
            cout << "    *\n";
            cout << "   **\n";
            cout << "  ***\n";
            cout << " ****\n";
            cout << "*****\n";
            break;

        case 3:
            cout << "*****\n";
            cout << " ****\n";
            cout << "  ***\n";
            cout << "   **\n";
            cout << "    *\n";
            break;

        case 4:
            cout << "   *   \n";
            cout << "  ***  \n";
            cout << " ***** \n";
            cout << "*******\n";
            break;

        case 5:
            cout << "   *   \n";
            cout << "  ***  \n";
            cout << " ***** \n";
            cout << "*******\n";
            cout << " ***** \n";
            cout << "  ***  \n";
            cout << "   *   \n";
            break;

        case 6:
            cout << "*   *\n";
            cout << " * * \n";
            cout << "  *  \n";
            cout << " * * \n";
            cout << "*   *\n";
            break;

        case 7:
            cout << "*    \n";
            cout << "**   \n";
            cout << "***  \n";
            cout << "**** \n";
            cout << "*****\n";
            break;

        case 8:
            cout << "    *\n";
            cout << "   **\n";
            cout << "  ***\n";
            cout << " ****\n";
            cout << "*****\n";
            break;

        case 9:
            cout << "   *   \n";
            cout << "  ***  \n";
            cout << " ***** \n";
            cout << "*******\n";
            break;

        case 10:
            cout << "*******\n";
            cout << " ***** \n";
            cout << "  ***  \n";
            cout << "   *   \n";
            break;

        case 0:
            cout << "вихід\n";
            break;

        default:
            cout << "невірний вибір\n";
        }
    } while (choice != 0);
    int again = 1;
    while (again != 0) {
        int n;
        cout << "введіть число: ";
        cin >> n;

        int temp = n;
        if (temp < 0) temp = -temp;

        if (temp == 0) {
            cout << "цифр: 1\n";
            cout << "сума: 0\n";
            cout << "середнє: 0\n";
            cout << "кількість нулів: 1\n";
        }
        else {
            int digits = 0, zeros = 0, sum = 0;
            while (temp > 0) {
                int d = temp % 10;
                if (d == 0) zeros++;
                sum += d;
                digits++;
                temp /= 10;
            }
            double avg = (double)sum / digits;
            cout << "цифр: " << digits << "\n";
            cout << "сума: " << sum << "\n";
            cout << "середнє: " << avg << "\n";
            cout << "кількість нулів: " << zeros << "\n";
        }

        cout << "\nповторити - 1, для виходу - 0: ";
        cin >> again;
    }
}
