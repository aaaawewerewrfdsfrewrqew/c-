#include <iostream>
#include <cmath>
using namespace std;
//1
void cube(int k = 1, int n = 1)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "@";
        }
        cout << endl;
    }
}
//2
int factorial(int number = 5)
{
    int factorial = 1;

    for (int i = 1; i <= number; ++i) {
        factorial *= i;
    }
    return factorial;
}
//4
int kub(int num = 1)
{
    int nak = 1;
    for (int i = 0; i < 3; i++)
    {
        nak *= num;
    }
    return nak;
}

//5
int biggestnumber(int num1 = 1, int num2 = 1)
{
    if(num1 > num2)
    {
        return num1;
    }

    else if (num1 < num2)
    {
        return num2;
    }

}

//6
bool dodat(int num1 = 1)
{
    bool answer;
    if (num1 > 0)
    {
        answer = true;
    }

    else if (num1 < 0)
    {
        answer = false;
    }
    return answer;
}

//2.1
void findMinMax(int arr[], int size)
{
    int min = arr[0];
    int max = arr[0];
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
    }

    cout << "Мінімум: " << min << " елемент під номером " << minIndex + 1 << endl;
    cout << "Максимум: " << max << " елемент під номером " << maxIndex + 1 << endl;
}

//2.2
void reverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

//2.3
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int countPrimes(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (isPrime(arr[i]))
            count++;
    return count;
}




//виконання
int main()
{
    cube(7, 8);

    int result_factorial = factorial(5);

    int result_kub = kub(5);

    int result_biggest = biggestnumber(5, 10);

	bool result_dodat = dodat(-12);

    cout << "\nФакторіал числа: " << result_factorial << endl;

    cout << "\nКуб числа: " << result_kub << endl;

    cout << "\nНайбільше з двох чисел: " << result_biggest << endl;

    cout << "\nЧисло додатнє? (1 - так, 0 - ні): " << result_dodat << endl;

    const int N = 10;
    int arr[N] = { 5, -2, 10, 0, 7, 3, -8, 9, 4, 2 };
    findMinMax(arr, N);

    const int A = 8;
    int array[A] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    cout << "масив до обернення: ";
    for (int i = 0; i < N; i++)
        cout << array[i] << " ";
    cout << endl;

    reverseArray(array, N);

    cout << "масив після обернення: ";
    for (int i = 0; i < N; i++)
        cout << array[i] << " ";
    cout << endl;

    const int S = 10;
    int arra[S] = { 2, 3, 4, 5, 9, 11, 13, 16, 17, 20 };
    cout << "Кількість простих чисел: " << countPrimes(arra, S) << endl;
}
