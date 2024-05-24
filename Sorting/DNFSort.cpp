#include<iostream>
using namespace std;


// Time: O(n)
// Space: O(1)
void dnfSort(int arr[], int n) {
    int low = -1, mid = 0, high = n;

    while(mid < high) {
        if(arr[mid] == 0) {
            low++;
            swap(arr[mid], arr[low]);
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            high--;
            swap(arr[mid], arr[high]);
        }
    }
}

int main() {
    int arr[] = {2, 0, 1, 1, 0, 1, 2, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    dnfSort(arr, n);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}