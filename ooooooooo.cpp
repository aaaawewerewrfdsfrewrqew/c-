#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int N1 = 10;
    int arr1[N1];

    srand(time(0));

    cout << "масив: ";
    for (int i = 0; i < N1; i++)
    {
        arr1[i] = rand() % 100 - 50;
        cout << arr1[i] << " ";
    }

    int min1 = arr1[0], max1 = arr1[0];

    for (int i = 1; i < N1; i++)
    {
        if (arr1[i] < min1) min1 = arr1[i];
        if (arr1[i] > max1) max1 = arr1[i];
    }

    cout << "\nмінімальний елемент: " << min1;
    cout << "\nмаксимальний елемент: " << max1 << "\n";

    const int M = 12;
    double profit[M];

    cout << "\nВведіть прибуток за 12 місяців:\n";
    for (int i = 0; i < M; i++)
    {
        cout << i + 1 << " місяць: ";
        cin >> profit[i];
    }

    int startMonth, endMonth;
    cout << "\nвведіть діапазон : ";
    cin >> startMonth >> endMonth;

    if (startMonth > endMonth)
    {
        int temp = startMonth;
        startMonth = endMonth;
        endMonth = temp;
    }

    double minProfit = profit[startMonth - 1], maxProfit = profit[startMonth - 1];
    int minMonth = startMonth, maxMonth = startMonth;

    for (int i = startMonth - 1; i < endMonth; i++)
    {
        if (profit[i] < minProfit)
        {
            minProfit = profit[i];
            minMonth = i + 1;
        }
        if (profit[i] > maxProfit)
        {
            maxProfit = profit[i];
            maxMonth = i + 1;
        }
    }

    cout << "\nмаксимальний прибуток у " << maxMonth << " місяці (" << maxProfit << ")";
    cout << "\nмінімальний прибуток у " << minMonth << " місяці (" << minProfit << ")\n";

    int N2;
    cout << "\nвведіть розмір масиву: ";
    cin >> N2;

    double arr2[100];

    cout << "введіть елементи масиву:\n";
    for (int i = 0; i < N2; i++)
        cin >> arr2[i];

    double sumNeg = 0;
    for (int i = 0; i < N2; i++)
        if (arr2[i] < 0) sumNeg += arr2[i];

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N2; i++)
    {
        if (arr2[i] < arr2[minIndex]) minIndex = i;
        if (arr2[i] > arr2[maxIndex]) maxIndex = i;
    }

    double prodBetween = 1;
    int startIndex = min(minIndex, maxIndex) + 1;
    int endIndex = max(minIndex, maxIndex);
    for (int i = startIndex; i < endIndex; i++)
        prodBetween *= arr2[i];

    double prodEven = 1;
    for (int i = 0; i < N2; i += 2)
        prodEven *= arr2[i];

    int firstNeg = -1, lastNeg = -1;
    for (int i = 0; i < N2; i++)
    {
        if (arr2[i] < 0)
        {
            if (firstNeg == -1) firstNeg = i;
            lastNeg = i;
        }
    }

    double sumBetweenNeg = 0;
    if (firstNeg != -1 && lastNeg != -1 && firstNeg < lastNeg)
    {
        for (int i = firstNeg + 1; i < lastNeg; i++)
            sumBetweenNeg += arr2[i];
    }

    cout << "\nсума від’ємних елементів: " << sumNeg;
    cout << "\nдобуток між min і max: " << prodBetween;
    cout << "\nдобуток елементів з парними номерами: " << prodEven;
    cout << "\nусма між першим і останнім від’ємними: " << sumBetweenNeg << endl;

    return 0;
}
