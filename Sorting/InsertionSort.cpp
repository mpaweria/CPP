#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i], j = i-1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n = 5;
    int arr[n] = {50, 40, 10, 30, 20};
    
    insertionSort(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}