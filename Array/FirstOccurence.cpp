#include<iostream>
using namespace std;

int main() {
    int n = 5, t = 20, i;
    int arr[5] = {10, 20, 30, 10 ,20};

    for(i=0; i<n; i++) {
        if(arr[i] == t)
        {
            cout << i << endl;
            break;
        }
    }
    if(i == n)
        cout << -1;

    return 0;
}