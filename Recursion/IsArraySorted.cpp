#include<iostream>
using namespace std;

bool isArraySorted(int arr[], int i, int n) {
    // base case
    if(i == n-1)
        return true;

    // recursive case

    return arr[i] < arr[i+1] && isArraySorted(arr, i+1, n);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    isArraySorted(arr, 0, 5) ? cout << "True" : cout << "False";

    return 0;
}