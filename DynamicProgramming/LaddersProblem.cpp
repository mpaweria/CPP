#include<iostream>
#include<vector>
using namespace std;

int numberOfWays(int n, int k, int i) {
    // base case
    if(i == n)
        return 1;

    // recursive case
    int count = 0;
    for(int j=1; j<=k; j++) {
        if(i+j <= n)
            count += numberOfWays(n, k, i+j);
    }
    return count;
}

int numberOfWaysTopDown(int n, int k, vector<int>& dp) {
    // look up
    if(dp[n] != -1)
        return dp[n];

    // base case
    if(n == 0)
        return dp[n] = 1;

    // recursive case
    int count = 0;
    for(int j=1; j<=k; j++) {
        if(j <= n)
            count += numberOfWaysTopDown(n-j, k, dp);
    }
    return dp[n] = count;
}

int numberOfWaysBottomUp(int n, int k) {
    vector<int> dp(n+1);
    dp[0] = 1;

    for(int i=0; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(i - j >= 0)
                dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int main() {
    int n = 4, k = 3;
    
    cout << numberOfWays(n, k, 0) << endl;

    vector<int> dp(n+1, -1);
    cout << numberOfWaysTopDown(n, k, dp) << endl;

    cout << numberOfWaysBottomUp(n, k) << endl;

    return 0;
}