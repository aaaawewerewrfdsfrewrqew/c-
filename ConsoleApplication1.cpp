#include <iostream>
using namespace std;

void findsymbol(int* pa)
{
    if (*pa > 0)
        cout << "symbol is +" << endl;
    else if (*pa < 0)
        cout << "symbol is -" << endl;
    else
        cout << "symbol is 0" << endl;
}


void swapv(int* pa, int* pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;

    cout << "first number after swapping: " << *pa << endl;
    cout << "second number after swapping: " << *pb << endl;
}

void calculate(double* pa, double* pb, char* pop, double* pres)
{
    if (*pop == '+')
        *pres = *pa + *pb;
    else if (*pop == '-')
        *pres = *pa - *pb;
    else if (*pop == '*')
        *pres = *pa * *pb;
    else if (*pop == '/')
    {
        if (*pb != 0)
            *pres = *pa / *pb;
        else
        {
            cout << "Error: division by zero!" << endl;
            return;
        }
    }
    else
    {
        cout << "Error: unknown operator!" << endl;
        return;
    }

    cout << "Result: " << *pres << endl;
}

int sumArray(int* arr, int size)
{
    int sum = 0;
    int* p = arr;

    for (int i = 0; i < size; i++)
    {
        sum += *(p + i);
    }

    return sum;
}


int main()
{
    srand(time(0));

    // 1
    int a, b;
    a = rand() % 100;
    b = rand() % 100;

    int* pa = &a;
    int* pb = &b;

    cout << "a = " << *pa << ", b = " << *pb << endl;
    if (*pa > *pb)
        cout << "biggest number: " << *pa << endl;
    else
        cout << "biggest number: " << *pb << endl;

    // 2
    int a1 = -1234;
    int b1 = 1234;
    int* pa1 = &a1;
    int* pb1 = &b1;

    findsymbol(pa1);
    findsymbol(pb1);

    // 3
    int a2 = -1234;
    int b2 = 1234;
    cout << "before swapping: a2 = " << a2 << ", b2 = " << b2 << endl;
    swapv(&a2, &b2);
    cout << "after swapping: a2 = " << a2 << ", b2 = " << b2 << endl;

    // 4
    double a3, b3, result;
    char op;

    double* pa3 = &a3;
    double* pb3 = &b3;
    double* pres = &result;
    char* pop = &op;

    cout << "enter first number: ";
    cin >> *pa3;

    cout << "enter operator (+, -, *, /): ";
    cin >> *pop;

    cout << "enter second number: ";
    cin >> *pb3;

    calculate(pa3, pb3, pop, pres);

    //5
    const int SIZE = 5;
    int arr[SIZE] = { 10, 20, 30, 40, 50 };

    int* pArr = arr;
    int total = sumArray(pArr, SIZE);

    cout << "array elements: ";
    for (int i = 0; i < SIZE; i++)
        cout << *(pArr + i) << " ";
    cout << "\nSum of array elements: " << total << endl;
}

