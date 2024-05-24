#include<iostream>
using namespace std;

void countingSort(int arr[], int n, int k) {
    int freq[k+1] = {};
    int res[n];

    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
    }
    for(int i=1; i<=k; i++) {
        freq[i] += freq[i-1];
    }
    for(int i=k; i>=1; i--) {
        freq[i] = freq[i-1];
    }
    freq[0] = 0;
    for(int i=0; i<n; i++) {
        res[freq[arr[i]]] = arr[i];
        freq[arr[i]]++;
    }

    for(int i=0; i<n; i++) {
        cout << res[i] << " ";
    }
}

int main() {
    int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
    int n = 9, k = 3;

    countingSort(arr, n, k);

    return 0;
}