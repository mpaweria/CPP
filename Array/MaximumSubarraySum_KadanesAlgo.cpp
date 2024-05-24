#include<iostream>
#include<climits>
using namespace std;

// Time: O(n)
// Space: O(n)
int kadanesAlgoLinearSpace(int arr[], int n) {
    int cSum[n];
    cSum[0] = arr[0];
    int maxSum = cSum[0];

    for(int i=1; i<n; i++) {
        cSum[i] = max(cSum[i-1] + arr[i] , arr[i]);
        maxSum = max(maxSum, cSum[i]);
    }
    return maxSum;
}

// Time: O(n)
// Space: O(1)
int kadanesAlgoConstantSpace(int arr[], int n) {
    int maxSum = arr[0], sum = arr[0];

    for(int i=1; i<n; i++) {
        sum = max(sum + arr[i] , arr[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    // int arr[] = {-3, 2, -1, 4, -5};
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << kadanesAlgoLinearSpace(arr, n);

    return 0;
}