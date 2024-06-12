#include<iostream>
using namespace std;

void nQueens(int n, int pos[], int r) {
    // base case
    if(r == n) {
        for(int i=0; i<n; i++) {
            cout << pos[i] << " ";
        }
        cout << endl;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(pos[i] == j)
                    cout << "Q ";
                else
                    cout << "_ ";
            }
            cout << endl;
        }
        cout << endl;

        return;
    }

    // recursive case
    for(int j=0; j<n; j++) {
        bool canPlace = true;

        for(int i=0; i<r; i++) {
            if(pos[i] == j || pos[i] == j + (r - i) || pos[i] == j - (r - i)) {
                canPlace = false;
                break;
            }
        }

        if(canPlace) {
            pos[r] = j;
            nQueens(n, pos, r+1);
        }
    }
}

int main() {
    int n = 4;
    int pos[10];

    nQueens(n, pos, 0);

    return 0;
}