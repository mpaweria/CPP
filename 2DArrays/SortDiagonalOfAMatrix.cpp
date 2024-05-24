#include<iostream>
#include<algorithm>
using namespace std;

void sortDiagonal(int arr[][4], int m, int n, int i, int j) {
    int diagonalLength = min(m-i, n-j);
    int vec[diagonalLength] = {};

    for(int k=0; k<diagonalLength; k++) {
        vec[k] = arr[i+k][j+k];
    }

    sort(vec, vec+diagonalLength);

    for(int k=0; k<diagonalLength; k++) {
        arr[i+k][j+k] = vec[k];
    }
}

void traverseDiagonal(int arr[][4], int m, int n) {
    for(int i=m-1; i>=1; i--) {
        sortDiagonal(arr, m, n, i, 0);
    }

    for(int j=0; j<n; j++) {
        sortDiagonal(arr, m, n, 0, j);
    }
}

int main() {
    int arr[][4] = {{11, 22, 18, 14},
                    {20, 21, 12, 13},
                    {19, 15, 16, 17}};

    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            cout  << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    traverseDiagonal(arr, 3, 4);

    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            cout  << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}