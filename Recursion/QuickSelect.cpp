#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int i = s-1, j = s, pivot = arr[e];

    while (j < e)
    {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i+1], arr[e]);

    return i+1;
}

int quickSelect(int arr[], int k, int s, int e) {
    int pi = partition(arr, s, e);

    if(pi == k){
        return arr[k];
    } else if(k < pi) {
        return quickSelect(arr, k, s, pi-1);
    } else {
        return quickSelect(arr, k, pi+1, e);
    }
}

int main() {
    int arr[] = {2, 7, 5, 3, 8, 4};
    int k = 3;

    cout << quickSelect(arr, k, 0, 5);

    return 0;
}