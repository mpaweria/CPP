#include<iostream>
#include<vector>
using namespace std;

int countWays(int n, int k) {
    // base case
    if(n<=1)
        return 1;

    // recursive case
    int totalWays = 0;
    for(int i=1; i<=k; i++){
        if(n-i >= 0)
            totalWays += countWays(n-i, k);
    }
    return totalWays;
}

int countWaysTopDown(int n, int k, vector<int>& dp) {
    // look up
    if(dp[n] != -1)
        return dp[n];

    // base case
    if(n<=1)
        return dp[n] = 1;

    // recursive case
    int totalWays = 0;
    for(int i=1; i<=k; i++){
        if(n-i >= 0)
            totalWays += countWaysTopDown(n-i, k, dp);
    }
    return dp[n] = totalWays;
}

int countWaysBottomUp(int n, int k) {
    vector<int>dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=1; j<=min(k,i); j++){
            dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int main() {
    int n = 4, k = 3;
    vector<int> dp(n+1, -1);

    cout << countWays(n, k) << endl;
    cout << countWaysTopDown(n, k, dp) << endl;
    cout << countWaysBottomUp(n, k) << endl;

    return 0;
}