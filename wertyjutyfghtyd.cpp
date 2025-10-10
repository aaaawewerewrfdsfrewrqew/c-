#include <iostream>
using namespace std;

int main() {
    char ch;
    int len, type, speed;

    cout << "Введіть символ ";
    cin >> ch;
    cout << "Введіть довжину лінії ";
    cin >> len;
    cout << "1 - горизонтальна, 2 - вертикальна ";
    cin >> type;
    cout << "Швидкість 1 - повільно 2 - нормально 3 - швидко ";
    cin >> speed;

    long delay = 0;
    if (speed == 1) delay = 100000000;
    else if (speed == 2) delay = 50000000;
    else delay = 10000000;

    for (int i = 0; i < len; i++) {
        cout << ch;
        if (type == 2) cout << endl;
        for (long j = 0; j < delay; j++);
    }
    cout << "\n";

    unsigned int seed = 12345;
    int userSum = 0, compSum = 0;

    for (int round = 1; round <= 3; round++) {
        cout << "\nкидок " << round << ":\n";
        cout << "натисніть будь яку клавішу і еnter, щоб кинути кубики: ";
        char temp;
        cin >> temp;

        seed = seed * 1103515245 + 12345;
        int a = (seed / 65536) % 6 + 1;
        seed = seed * 1103515245 + 12345;
        int b = (seed / 65536) % 6 + 1;
        int u = a + b;
        cout << "ваші кубики: " << a << " і " << b << " (сума = " << u << ")\n";
        userSum += u;

        seed = seed * 1103515245 + 12345;
        a = (seed / 65536) % 6 + 1;
        seed = seed * 1103515245 + 12345;
        b = (seed / 65536) % 6 + 1;
        int c = a + b;
        cout << "кубики комп'ютера: " << a << " і " << b << " (сума = " << c << ")\n";
        compSum += c;
    }

    cout << "\nваш результат: " << userSum << ", комп'ютера: " << compSum << endl;
    if (userSum > compSum) cout << "ви перемогли!\n";
    else if (userSum < compSum) cout << "переміг комп'ютер!\n";
    else cout << "Нічия!\n";

    int n;
    cout << "введіть розмір масиву: ";
    cin >> n;
    int arr[100];
    seed = 54321;

    for (int i = 0; i < n; i++) {
        seed = seed * 1103515245 + 12345;
        arr[i] = (seed / 65536) % 100 - 50;
        cout << arr[i] << " ";
    }
    cout << endl;

    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    cout << "Мінімальний: " << min << ", максимальний: " << max << endl;


    double profit[12];
    for (int i = 0; i < 12; i++) {
        cout << "прибуток за " << i + 1 << " місяць ";
        cin >> profit[i];
    }
    int start, end;
    cout << "Введіть діапазон (наприклад 3 і 6): ";
    cin >> start >> end;

    if (start > end) {
        int t = start;
        start = end;
        end = t;
    }

    double minP = profit[start - 1];
    double maxP = profit[start - 1];
    int minM = start, maxM = start;

    for (int i = start - 1; i < end; i++) {
        if (profit[i] < minP) {
            minP = profit[i];
            minM = i + 1;
        }
        if (profit[i] > maxP) {
            maxP = profit[i];
            maxM = i + 1;
        }
    }

    cout << "мінімальний прибуток у місці " << minM << " (" << minP << ")\n";
    cout << "максимальний прибуток у місяці " << maxM << " (" << maxP << ")\n";


    int N;
    cout << "введіть розмір масиву N ";
    cin >> N;
    double A[100];
    for (int i = 0; i < N; i++) {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    double sumNeg = 0;
    for (int i = 0; i < N; i++)
        if (A[i] < 0) sumNeg += A[i];
    cout << "сума від’ємних елементів: " << sumNeg << endl;

    int minI = 0, maxI = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] < A[minI]) minI = i;
        if (A[i] > A[maxI]) maxI = i;
    }

    double prodBetween = 1;
    if (minI > maxI) {
        int t = minI;
        minI = maxI;
        maxI = t;
    }
    for (int i = minI + 1; i < maxI; i++)
        prodBetween *= A[i];
    cout << "добуток між min і max  " << prodBetween << endl;

    double prodEven = 1;
    for (int i = 0; i < N; i += 2)
        prodEven *= A[i];
    cout << "добуток елементів з парними номерами: " << prodEven << endl;

    int firstNeg = -1, lastNeg = -1;
    for (int i = 0; i < N; i++)
        if (A[i] < 0) {
            if (firstNeg == -1) firstNeg = i;
            lastNeg = i;
        }

    double sumBetween = 0;
    if (firstNeg != -1 && lastNeg != -1 && firstNeg < lastNeg) {
        for (int i = firstNeg + 1; i < lastNeg; i++)
            sumBetween += A[i];
    }
    cout << "Сума між першим і останнім від’ємними " << sumBetween << endl;

    return 0;
}
