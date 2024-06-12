#include<iostream>
using namespace std;

void merge(int arr[], int s, int m, int e) {
    int temp[e+1] = {};
    int i = s, j = m + 1, k = s;

    while (i <= m && j <= e)    
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= m)
        temp[k++] = arr[i++];
    while(j <= e)
        temp[k++] = arr[j++];

    for(int l=s; l<=e; l++)
        arr[l] = temp[l];
}

void mergeSort(int arr[], int s, int e) {
    // base case
    if(s == e)
        return;

    // recursive case
    int m = s + (e - s) / 2;

    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);

    merge(arr, s, m, e);
}

int main() {
    int arr[] = {50, 30, 40, 10, 20};

    mergeSort(arr, 0, 4);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}