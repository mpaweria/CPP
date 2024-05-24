#include<iostream>
using namespace std;

int goodSubArray(int arr[], int n) {
    int freq[n] = {};
    freq[0] = 1;
    int csum = 0;

    for(int i=0; i<n; i++) {
        csum += arr[i];
        freq[((csum % n) + n) % n]++;
    }

    int count = 0;
    for(int i=0; i<n; i++) {
        int xi = freq[i];
        if(xi >= 2) {
            count += (xi * (xi-1)) / 2;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 6, 5, 2 ,4, 3};
    int n = 6;

    cout << goodSubArray(arr, n);
}