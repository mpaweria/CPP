#include<iostream>
using namespace std;

void uniqueNumber(int arr[], int n) {
    int firstNum = 0, secondNum = 0, ans = 0, pos = 0;

    for(int i=0; i<n; i++) {
        ans ^= arr[i];
    }

    while((ans & 1)==0) {
        pos++;
        ans >>= 1;
    }
    
    int mask = 1 << pos;

    for(int i=0; i<n; i++) {
        if(arr[i] & mask)
            firstNum ^= arr[i];
        else
            secondNum ^= arr[i];
    }
    cout << firstNum << " " << secondNum << endl;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    uniqueNumber(arr, n);

    return 0;
}