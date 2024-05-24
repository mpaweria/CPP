#include<iostream>
using namespace std;

int main() {
    int n = 7, k = 3;
    int arr[n] = {10, 20, 30, 40, 50, 60, 70};
    k = k % n;

    cout << "Original Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    // It has O(kn) time complexity
    // while(k % n) {
    //     int temp = arr[n-1];
    //     for(int i=n-2; i>=0; i--) {
    //         arr[i+1] = arr[i];
    //     }
    //     arr[0] = temp;
    //     k--;
    // }

    // This will have O(n)
    // Reverse the entire array, O(n/2)
    int i=0, j=n-1;
    while(i < j) {          
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    // Reverse first K elements, O(k/2) 
    i=0, j=k-1;
    while(i < j) {          
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    //Reverse last n-k elements, O((n-k)/2)
    i=k, j=n-1;
    while(i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    cout << endl << "Rotated array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}