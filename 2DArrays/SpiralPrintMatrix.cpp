#include<iostream>
using namespace std;

void spiralPrintMatrix(int arr[][4], int m, int n) {
    int sr = 0, sc = 0, er = m-1, ec = n-1;
    while (sc <= ec && sr <= er)
    {
        for(int j=sc; j<=ec; j++)
            cout << arr[sr][j] << " ";  
        sr++;

        for(int i=sr; i<=er; i++)
            cout << arr[i][ec] << " "; 
        ec--;

        if(sr <= er) {
            for(int j=ec; j>=sc; j--)
                cout << arr[er][j] << " ";
            er--;
        }

        if(sc <= ec) {
            for(int i=er; i>=sr; i--)
                cout << arr[i][sc] << " ";
            sc++;
        }
    }
    
}

int main() {
    int arr[][4] = {{11, 12, 13, 14},
                    {22, 23, 24, 15},
                    {21, 26, 25, 16},
                    {20, 19, 18, 17}};

    spiralPrintMatrix(arr, 4, 4);
}