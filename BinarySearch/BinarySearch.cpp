#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int t) {
    int s = 0, e = n-1;

    while (s <= e)
    {
        int mid = (s+e)/2;  // or mid = s + (e - s)/2, it avoids integer overflow
        if(arr[mid] == t)
            return mid;
        else if(arr[mid] > t)
            e = mid-1;
        else
            s = mid+1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int t = 40, n = sizeof(arr)/sizeof(arr[0]);

    cout << t << " is found at index " << binarySearch(arr, n, t);
}