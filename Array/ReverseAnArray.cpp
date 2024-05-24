#include<iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[n] = {10, 20, 30, 40, 50, 60, 70, 80};

    cout << "Initial Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    for(int i=0; i<n/2; i++) {
        swap(arr[i], arr[n-1-i]);
    }

    cout << endl << "Reversed Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}