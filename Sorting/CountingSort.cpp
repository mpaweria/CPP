#include<iostream>
using namespace std;

// Time: O(n)
// Space: O(k)
// This is non stable version of Counting Sort, this means that the order of the elements is not preserved.
void countingSort(int arr[], int n, int k) {
    int freq[k+1] = {};

    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
    }
    int j=0;
    for(int i=0; i<=k; i++) {
        while(freq[i]--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
    int n = 9, k = 3;

    countingSort(arr, n, k);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}