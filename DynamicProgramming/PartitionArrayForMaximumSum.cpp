// arr = {1, 2, 3, 4, 5, 6}, k=1;
// arr = {1, 15, 7, 9, 2, 5, 10}, k = 3; 

#include<iostream>
#include<vector>

using namespace std;

int maxSumAfterPartitioning(vector<int> arr, int n, int k, int i) {
    // base case
    if(i == n)
        return 0;

    // recursive case
    int maxSoFar = 0, maxNum = 0;
    for(int j=i; j<n && j<i+k; j++) {
        maxNum = max(maxNum, arr[j]);
        maxSoFar = max(maxSoFar, maxNum * (j-i+1) + maxSumAfterPartitioning(arr, n, k, j+1));
    }
    return maxSoFar;
}

int maxSumAfterPartitioningTopDown(vector<int> arr, int n, int k, int i, vector<int> &dp) {
    // look up
    if(dp[i] != -1)
        return dp[i];

    // base case
    if(i == n)
        return dp[i] = 0;

    // recursive case
    int maxSoFar = 0, maxNum = 0;
    for(int j=i; j<n && j<i+k; j++) {
        maxNum = max(maxNum, arr[j]);
        maxSoFar = max(maxSoFar, maxNum * (j-i+1) + maxSumAfterPartitioningTopDown(arr, n, k, j+1, dp));
    }
    return dp[i] = maxSoFar;
}

int maxSumAfterPartitioningBottomUp(vector<int> arr, int n, int k) {
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0; i--) {
        int maxSoFar = 0, maxNum = 0;
        for(int j=i; j<n && j<i+k; j++) {
            maxNum = max(maxNum, arr[j]);
            maxSoFar = max(maxSoFar, maxNum * (j-i+1) + dp[j+1]);
        }
        dp[i] = maxSoFar;
    }
    return dp[0];
}

int main() {

	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3, n = arr.size();

	cout << maxSumAfterPartitioning(arr, n, k, 0) << endl;

    vector<int> dp(n+1, -1);
    cout << maxSumAfterPartitioningTopDown(arr, n, k, 0, dp) << endl;

    cout << maxSumAfterPartitioningBottomUp(arr, n, k) << endl;

	return 0;
}