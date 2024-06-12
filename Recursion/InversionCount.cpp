#include<iostream>
using namespace std;

int merge(int arr[], int s, int m, int e) {
    int i = s, j = m+1, k = s, count = 0;
    int temp[e+1] = {};

    while (i <= m && j <= e)
    {
        if(arr[i] > arr[j]) {
            count += m - i + 1;
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }
    while(i <= m)
        temp[k++] = arr[i++];
    while(j <= e)
        temp[k++] = arr[j++];

    for(int l=s; l<=e; l++)
        arr[l] = temp[l];

    return count;    
}

int inversionCount(int arr[], int s, int e) {
    // base case
    if(s == e)
        return 0;

    // recursive case
    int m = s + (e - s)/2;

    return inversionCount(arr, s, m) + inversionCount(arr, m+1, e) + merge(arr, s, m, e);
}

int main() {
    int arr[] = {2, 7, 5, 8, 3, 4};

    cout << inversionCount(arr, 0, 6);

    return 0;
}