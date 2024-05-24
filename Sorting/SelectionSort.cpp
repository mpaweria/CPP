#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n = 5;
    int arr[n] = {50, 40, 10, 30, 20};
    
    selectionSort(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}