#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int count = 0;
    for(int i=1; i<=n-1; i++) {
        bool swapped = false;
        for(int j=0; j<n-i; j++) {
            count++;
            if(arr[j] > arr[j+1]) {
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if(!swapped)
            break;
    }
    cout << count << endl;
}

int main() {
    int n = 5;
    int arr[n] = {10, 20, 30, 40, 50};
    
    bubbleSort(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}