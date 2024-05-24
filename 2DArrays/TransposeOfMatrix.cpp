#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[][4] = {{11, 12, 13, 14},
                    {15, 16, 17, 18},
                    {19, 20, 21, 22},
                    {23, 24, 25, 26}};

    int ans[4][4] = {};

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            ans[j][i] = arr[i][j];
        }
    }

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<4; i++) {
        for(int j=i+1; j<4; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    cout << endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}