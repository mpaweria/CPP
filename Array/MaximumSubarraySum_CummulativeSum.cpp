#include<iostream>
#include<climits>
using namespace std;

// Time: O(n^2)
// Space: O(n)
int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]), maxSum = INT_MIN;
    int cSum[n+1];
    cSum[0] = 0;

    for(int i=1; i<=n; i++) {
        cSum[i] = cSum[i-1] + arr[i-1];
    }

    for(int i=0; i<n; i++) {   
        for(int j=i; j<n; j++) {
            int sum = cSum[j+1] - cSum[i];
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum;

    return 0;
}