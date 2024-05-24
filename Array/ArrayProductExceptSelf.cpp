#include<iostream>
using namespace std;

// Brute force approach -> Time: O(n^2)
// void productExceptSelf(int arr[], int n) {
//     int res[n] = {};

//     for(int i=0; i<n; i++) {
//         int prod = 1;
//         for(int j=0; j<n; j++) {
//             if(i == j)
//                 continue;
//             prod *= arr[j];
//         }
//         res[i] = prod;
//     }

//     for(int i=0; i<n; i++)
//         cout << res[i] << " ";
// }

// Time: O(n)
// void productExceptSelf(int arr[], int n) {
//     int prod = 1;

//     for(int i=0; i<n; i++) {
//         prod *= arr[i];
//     }

//     for(int i=0; i<n; i++) {
//         arr[i] = prod / arr[i];
//     }
// }

// If using division operator is not allowed
// Time: n+n+n = 3n ~ O(n)
// Space: O(n)
void productExceptSelf(int arr[], int n) {
    int left[n], right[n];
    left[0] = 1;
    right[n-1] = 1;

    for(int i=1; i<n; i++) {
        left[i] = arr[i-1] * left[i-1];
    }

    for(int i=n-2; i>=0; i--) {
        right[i] = arr[i+1] * right[i+1];
    }

    for(int i=0; i<n; i++) {
        arr[i] = left[i] * right[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    productExceptSelf(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}