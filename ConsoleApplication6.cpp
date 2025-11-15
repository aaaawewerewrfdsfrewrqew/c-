#include <iostream>
using namespace std;

int* mergeArrays(int* A, int M, int* B, int N, int& sizeC) {
    sizeC = M + N;
    int* C = new int[sizeC];
    for (int i = 0; i < M; i++) C[i] = A[i];
    for (int i = 0; i < N; i++) C[M + i] = B[i];
    return C;
}

bool exists(int* arr, int size, int x) {
    for (int i = 0; i < size; i++)
        if (arr[i] == x) return true;
    return false;
}

int* intersectionNoRepeat(int* A, int M, int* B, int N, int& sizeC) {
    int* C = new int[(M < N ? M : N)];
    sizeC = 0;

    for (int i = 0; i < M; i++) {
        if (exists(B, N, A[i]) && !exists(C, sizeC, A[i])) {
            C[sizeC++] = A[i];
        }
    }
    return C;
}

int* removeEvenOrOdd(int* A, int M, int choice, int& newSize) {
    int* B = new int[M];
    newSize = 0;

    for (int i = 0; i < M; i++) {
        if (choice == 1 && A[i] % 2 != 0)
            B[newSize++] = A[i];
        if (choice == 2 && A[i] % 2 == 0)
            B[newSize++] = A[i];
    }
    return B;
}


int main() {

    int A[5] = { 1, 2, 3, 4, 5 };
    int B[5] = { 3, 4, 5, 6, 7 };

    int sizeC;
    int* C = mergeArrays(A, 5, B, 5, sizeC);

    for (int i = 0; i < sizeC; i++) cout << C[i] << " ";
    cout << endl;
    delete[] C;

    int sizeI;
    int* I = intersectionNoRepeat(A, 5, B, 5, sizeI);

    for (int i = 0; i < sizeI; i++) cout << I[i] << " ";
    cout << endl;
    delete[] I;

    int sizeR;
    int* R = removeEvenOrOdd(A, 5, 1, sizeR);

    for (int i = 0; i < sizeR; i++) cout << R[i] << " ";
    cout << endl;
    delete[] R;
}