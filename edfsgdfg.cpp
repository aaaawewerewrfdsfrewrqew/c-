#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int a1[5], a2[5];

    cout << "введіть 10 елементів масиву:\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        a1[i] = arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        a2[i] = arr[i + 5];
    }

    cout << "\nперший масив: ";
    for (int i = 0; i < 5; i++)
        cout << a1[i] << " ";

    cout << "\nдругий масив: ";
    for (int i = 0; i < 5; i++)
        cout << a2[i] << " ";


    int a[5], b[5], c[5];

    cout << "5 елементів першого масиву:\n";
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    cout << "5 елементів другого масиву:\n";
    for (int i = 0; i < 5; i++)
        cin >> b[i];

    for (int i = 0; i < 5; i++)
        c[i] = a[i] + b[i];

    cout << "\nрезультат: ";
    for (int i = 0; i < 5; i++)
        cout << c[i] << " ";

    return 0;
}
