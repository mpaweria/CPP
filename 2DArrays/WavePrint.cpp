#include<iostream>
using namespace std;

int main() {
    int arr[][3] = {{10, 20, 30},
                    {40, 50, 60},
                    {70, 80, 90}};

    for(int j=0; j<3; j++) {
        if(j%2 == 0) {
            for(int i=0; i<3; i++)
                cout << arr[i][j] << " ";
        } else {
            for(int i=2; i>=0; i--)
                cout << arr[i][j] << " ";
        }        
    }
    return 0;
}