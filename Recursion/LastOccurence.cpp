#include<iostream>
using namespace std;

int lastOccurence(int arr[], int n, int t) {
    // base case
    if(n == -1)
        return -1;

    // recursive case
    if(arr[n-1] == t)
        return n-1;
    
    return lastOccurence(arr, n-1, t);
}

int main() {
    int n = 8, t = 30;
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};

    cout << "Last occurence of " << t << " in array is at index " << lastOccurence(arr, n, t);

    return 0;
}