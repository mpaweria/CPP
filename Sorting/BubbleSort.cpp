#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=1; i<=n-1; i++) {
        for(int j=0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n = 5;
    int arr[n] = {50, 40, 30, 20, 10};
    
    bubbleSort(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}