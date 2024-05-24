#include<iostream>
using namespace std;

int main() {
    int n = 5, t = 10;
    int arr[5] = {10, 20, 30, 10, 20};
    int i, flag = 0;

    for(i=0; i<n; i++) {
        if(arr[i] == t) {
            cout << i << " ";
            flag = 1;
        }
    }
    if(!flag)
        cout << -1;

    return 0;
}