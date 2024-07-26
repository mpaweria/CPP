#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int LIS(vector<int> vec, int n, int i) {
    // base case
    if(i == n)
        return 0;

    // recursive case
    int maxSoFar = INT_MIN;
    for(int j=i+1; j<n; j++) {
        if(vec[j] >= vec[i])
            maxSoFar = max(maxSoFar, LIS(vec, n, j));
    }
    return maxSoFar == INT_MIN ? 1 : 1 + maxSoFar;
}

int LISTopDown(vector<int> vec, int n, int i, vector<int> &dp) {
    // look up
    if(dp[i] != -1)
        return dp[i];
    
    // base case
    if(i == n)
        return dp[i] = 0;

    // recursive case
    int maxSoFar = INT_MIN;
    for(int j=i+1; j<n; j++) {
        if(vec[j] >= vec[i])
            maxSoFar = max(maxSoFar, LISTopDown(vec, n, j, dp));
    }
    return dp[i] = maxSoFar == INT_MIN ? 1 : 1 + maxSoFar;
}

int LISBottomUp(vector<int> vec, int n, int k) {
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=k; i--) {
        int maxSoFar = INT_MIN;
        for(int j=i+1; j<n; j++) {
            if(vec[j] >= vec[i])
                maxSoFar = max(maxSoFar, dp[j]);
        }
        dp[i] = maxSoFar == INT_MIN ? 1 : 1 + maxSoFar;
    }
    return dp[k];
}

int main() {
    vector<int> vec = {1, 2, 5, 3, 0, 4, 6};
    int n = 7, k = 1;

    cout << LIS(vec, n, k) << endl;

    vector<int> dp(n+1, -1);
    cout << LISTopDown(vec, n, k, dp) << endl;

    cout << LISBottomUp(vec, n, k) << endl;

    return 0;
}