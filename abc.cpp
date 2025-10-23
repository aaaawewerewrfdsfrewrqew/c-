#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    const int rows=5;
    const int cols=5;
    int array[rows][cols];
    int a;
    cout << "enter number\n";
    cin >> a;
    array[0][0] = a;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0) continue;
            if (j == 0)
                array[i][j] = array[i - 1][cols - 1] * 2;
            else
                array[i][j] = array[i][j - 1] * 2;
        }
    }

    cout << "array is \n";
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << array[i][j] <<"\t";

        }
        cout << endl;
    }

    const int ROWS2 = 3, COLS2 = 4;
    int arr2[ROWS2][COLS2];

    int start2;
    cout << "enter number: ";
    cin >> start2;

    arr2[0][0] = start2;
    for (int i = 0; i < ROWS2; i++)
    {
        for (int j = 0; j < COLS2; j++)
        {
            if (i == 0 && j == 0) continue;
            if (j == 0)
                arr2[i][j] = arr2[i - 1][COLS2 - 1] + 1;
            else
                arr2[i][j] = arr2[i][j - 1] + 1;
        }
    }

    cout << "array:\n";
    for (int i = 0; i < ROWS2; i++)
    {
        for (int j = 0; j < COLS2; j++)
            cout << arr2[i][j] << "\t";
        cout << endl;
    }   

    const int ROWS3 = 2, COLS3 = 6;
    int arr3[ROWS3][COLS3];

    srand(time(0));
    for (int i = 0; i < ROWS3; i++)
        for (int j = 0; j < COLS3; j++)
            arr3[i][j] = rand() % 10;

    cout << "start array:\n";
    for (int i = 0; i < ROWS3; i++)
    {
        for (int j = 0; j < COLS3; j++)
            cout << arr3[i][j] << "\t";
        cout << endl;
    }

    int shift, dir;
    cout << "\nnumber of offsets: ";
    cin >> shift;
    cout << "choose direction:\n";
    cout << "1 - right\n2 - left\n3 - down\n4 - up\nyour choise: ";
    cin >> dir;

    int temp[ROWS3][COLS3];

    if (dir == 1)
    {
        for (int i = 0; i < ROWS3; i++)
            for (int j = 0; j < COLS3; j++)
                temp[i][(j + shift) % COLS3] = arr3[i][j];
    }
    else if (dir == 2)
    {
        for (int i = 0; i < ROWS3; i++)
            for (int j = 0; j < COLS3; j++)
                temp[i][(j - shift + COLS3) % COLS3] = arr3[i][j];
    }
    else if (dir == 3)
    {
        for (int i = 0; i < ROWS3; i++)
            for (int j = 0; j < COLS3; j++)
                temp[(i + shift) % ROWS3][j] = arr3[i][j];
    }
    else if (dir == 4)
    {
        for (int i = 0; i < ROWS3; i++)
            for (int j = 0; j < COLS3; j++)
                temp[(i - shift + ROWS3) % ROWS3][j] = arr3[i][j];
    }
    else
    {
        cout << "wrong!\n";
        return 0;
    }

    cout << "\nresult after offset:\n";
    for (int i = 0; i < ROWS3; i++)
    {
        for (int j = 0; j < COLS3; j++)
            cout << temp[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
