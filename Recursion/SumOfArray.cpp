#include<iostream>
using namespace std;

int arraySum(int arr[], int i, int n) {
    // base case
    if(i == n)
        return 0;

    // recursive case
    return arr[i] + arraySum(arr, i+1, n);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    cout << arraySum(arr, 0, 5);

    return 0;
}