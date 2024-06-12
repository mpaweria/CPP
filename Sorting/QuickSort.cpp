#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[e], i = s-1, j = s;

    while (j < e)
    {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[++i], arr[e]);

    return i;
}

void quickSort(int arr[], int s, int e) {
    // base case
    if(s >= e)
        return;

    // recursive case
    int pi = partition(arr, s, e);
    quickSort(arr, s, pi-1);
    quickSort(arr, pi+1, e);
}

int main() {
    int arr[] = {60, 50, 20, 10, 40, 30};

    quickSort(arr, 0, 5);

    // for(int i: arr)
    //     cout << i << " ";

    for(int i=0; i<6; i++)
        cout << arr[i] << " ";

    return 0;
}