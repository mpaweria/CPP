#include<iostream>
using namespace std;

int firstOccurence(int arr[], int n, int t, int i) {
    // base case
    if(i == n)
        return -1;

    // recursive case
    if(arr[i] == t)
        return i;
    
    return firstOccurence(arr, n, t, i+1);
}

int main() {
    int n = 8, t = 30;
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};

    cout << "First occurence of " << t << " in array is at index " << firstOccurence(arr, n, t, 0);

    return 0;
}