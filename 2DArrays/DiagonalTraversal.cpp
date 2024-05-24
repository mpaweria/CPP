#include<iostream>
using namespace std;

void printDiagonal(int arr[][4], int m, int n, int i, int j) {
    int diagonalLength = min(m-i, n-j);

    for(int k=0; k<diagonalLength; k++) {
        cout << arr[i+k][j+k] << " ";
    }
}

void traverseDiagonal(int arr[][4], int m, int n) {
    for(int i=m-1; i>=1; i--) {
        printDiagonal(arr, m, n, i, 0);
    }

    for(int j=0; j<n; j++) {
        printDiagonal(arr, m, n, 0, j);
    }
}

int main() {
    int arr[][4] = {{11, 12, 13, 14},
                    {15, 16, 17, 18},
                    {19, 20, 21, 22}};

    traverseDiagonal(arr, 3, 4);

    return 0;
}