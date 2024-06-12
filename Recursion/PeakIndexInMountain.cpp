#include<iostream>
using namespace std;

int findPeak(int arr[], int s, int e) {
    // base case
    if(s > e) {
        return arr[(s + e)/2];
    }

    // recursive case
    int m1 = s + (e - s) / 3;
    int m2 = e - (e - s) / 3;

    if(arr[m1] > arr[m2]) {
        return findPeak(arr, s, m2-1);
    }
    return findPeak(arr, m1+1, e);
}

int main() {
    int arr[] = {0, 1, 3, 10, 3, 1, 0};     // unimodal sequence

    cout << findPeak(arr, 0, 6);

    return 0;
}