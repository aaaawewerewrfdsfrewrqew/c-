#include <iostream>
using namespace std;

int** c2darray(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];
    return arr;
}

void delarray(int** arr, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

void outarray(int** arr, int rows, int cols) {
    cout << "array (" << rows << " * " << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "\n";
}

void pushBackRow(int**& arr, int& rows, int cols, int* newRow) {
    int** temp = new int* [rows + 1];

    for (int i = 0; i < rows; i++)
        temp[i] = arr[i];

    temp[rows] = newRow;

    delete[] arr;
    arr = temp;
    rows++;
}

void pushFrontRow(int**& arr, int& rows, int cols, int* newRow) {
    int** temp = new int* [rows + 1];

    temp[0] = newRow;

    for (int i = 0; i < rows; i++)
        temp[i + 1] = arr[i];

    delete[] arr;
    arr = temp;
    rows++;
}

void insertRow(int**& arr, int& rows, int cols, int* newRow, int pos) {
    if (pos < 0) pos = 0;
    if (pos > rows) pos = rows;

    int** temp = new int* [rows + 1];

    for (int i = 0; i < pos; i++)
        temp[i] = arr[i];

    temp[pos] = newRow;

    for (int i = pos; i < rows; i++)
        temp[i + 1] = arr[i];

    delete[] arr;
    arr = temp;
    rows++;
}

void delrow(int**& arr, int& rows, int pos) {
    if (pos < 0 || pos >= rows) return;

    delete[] arr[pos];

    int** temp = new int* [rows - 1];

    for (int i = 0; i < pos; i++)
        temp[i] = arr[i];

    for (int i = pos + 1; i < rows; i++)
        temp[i - 1] = arr[i];

    delete[] arr;
    arr = temp;
    rows--;
}


bool rowHasZero(int* row, int cols) {
    for (int i = 0; i < cols; i++)
        if (row[i] == 0) return true;
    return false;
}


int main() {
    int rows = 2, cols = 3;
    int** arr = c2darray(rows, cols);
    int value = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = value++;

    cout << "start array:\n";
    outarray(arr, rows, cols);
    int* r1 = new int[cols] {10, 10, 10};
    pushBackRow(arr, rows, cols, r1);
    cout <<"array after adding row in end:\n";
    outarray(arr, rows, cols);
    int* r2 = new int[cols] {20, 20, 20};
    pushFrontRow(arr, rows, cols, r2);
    cout << "after adding row in the start:\n";
    outarray(arr, rows, cols);

    int* r3 = new int[cols] {30, 30, 30};
    insertRow(arr, rows, cols, r3, 2);
    cout << "after adding row to position 2:\n";
    outarray(arr, rows, cols);

    delrow(arr, rows, 1);
    cout << "after deleting first row:\n";
    outarray(arr, rows, cols);

    delarray(arr, rows);

    int rows1, cols1;
    cout << "Rows: ";
    cin >> rows1;
    cout << "Cols: ";
    cin >> cols1;

    int** A1 = c2darray(rows1, cols1);

    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++)
            A1[i][j] = rand() % 10;

    cout << "\nstart array:\n";
    outarray(A1, rows1, cols1);

    for (int i = 0; i < rows1; i++) {
        if (rowHasZero(A1[i], cols1)) {
            delrow(A1, rows1, i);
            i--;
        }
    }

    cout << "array after deleting rows with 0:\n";
    outarray(A1, rows1, cols1);

    delarray(A1, rows1);


    int rows2, cols2;
    cout << "rows: ";
    cin >> rows2;
    cout << "cols: ";
    cin >> cols2;

    int** A2 = c2darray(rows2, cols2);
    int** B2 = c2darray(rows2, cols2);
    int** C2 = c2darray(rows2, cols2);

    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++) {
            A2[i][j] = rand() % 10;
            B2[i][j] = rand() % 10;
        }

    cout << "\nmatrix A:\n";
    outarray(A2, rows2, cols2);

    cout << "Matrix B:\n";
    outarray(B2, rows2, cols2);

    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++)
            C2[i][j] = A2[i][j] + B2[i][j];

    cout << "A + B =\n";
    outarray(C2, rows2, cols2);

    delarray(A2, rows2);
    delarray(B2, rows2);
    delarray(C2, rows2);

}