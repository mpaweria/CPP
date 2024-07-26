#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int coinChange(vector<int> coins, int i, int n) {
    // base case
    if(n == 0 || i >= coins.size())
        return n == 0 ? 0 : INT_MAX - 1;

    // recursive case
    int res = -1;
    if(coins[i] > n) {
        int donotUse = coinChange(coins, i+1, n);
        res = donotUse;
    } else {
        int donotUse = coinChange(coins, i+1, n);
        int use = 1 + coinChange(coins, i, n-coins[i]);
        res = min(donotUse, use);
    }
    return res;
}

int coinChangeTopDown(vector<int> coins, int i, int n, vector<vector<int>> dp) {
    // lookup
    if(dp[i][n] != -1)
        return dp[i][n];

    // base case
    if(n == 0 || i >= coins.size())
        return dp[i][n] = n == 0 ? 0 : INT_MAX - 1;

    // recursive case
    int res = -1;
    if(coins[i] > n) {
        int donotUse = coinChange(coins, i+1, n);
        res = donotUse;
    } else {
        int donotUse = coinChange(coins, i+1, n);
        int use = 1 + coinChange(coins, i, n-coins[i]);
        res = min(donotUse, use);
    }
    return dp[i][n] = res;
}

int coinChangeBottomUp(vector<int> coins, int size, int n) {
    vector<vector<int>> dp(13, vector<int>(n+1));

    for(int i=0; i<=size; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = j == 0 ? 0 : INT_MAX-1;
        }
    }

    for(int i=1; i<=size; i++) {
        for(int j=1; j<=n; j++) {
            if(coins[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
        }
    }
    return dp[size][n];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int n = 11;

    cout << coinChange(coins, 0, n) << endl;

    vector<vector<int>> dp(13, vector<int>(n + 1, -1));
    cout << coinChangeTopDown(coins, 0, n, dp) << endl;

    cout << coinChangeBottomUp(coins, coins.size(), n) << endl;

    return 0;
}