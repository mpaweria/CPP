#include<iostream>
using namespace std;

int main() {
    int n = 5, t = 10;
    int arr[5] = {10, 20, 30, 10, 20};
    int i, idx = -1;

    // This loop runs n times
    // for(i=0; i<n; i++) {
    //     if(arr[i] == t)
    //         idx = i;
    // }

    // cout << idx;

    // This will run till the first occurence from the end i.e last occurence of the element which in avg cases will be less than n
    for(i=n-1; i>=0; i--) {
        if(arr[i] == t) {
            cout << i << endl;
            break;
        }
    }
    if(i == -1)
        cout << -1;

    return 0;
}