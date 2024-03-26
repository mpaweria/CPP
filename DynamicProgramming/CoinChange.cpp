#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int changeCoins(vector<int> coins, int l, int n) {
    // base case
    if(n == 0)
        return 0;

    // recursive case
    int minCoinsRequired = INT_MAX;
    for(int i=0; i<l; i++) {
        if(coins[i] <= n){
            int curr = changeCoins(coins, l, n-coins[i]);
            minCoinsRequired = min(minCoinsRequired, curr+1);
        }
    }
    return minCoinsRequired;
}

int changeCoinsTopDown(vector<int> coins, int n, vector<int>& dp) {
    // look up 
    if(dp[n] != -1)
        return dp[n];

    // base case
    if(n <= 0)
        return 0;

    // recursive case
    int minCoinsRequired = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        if(coins[i] <= n){
            int curr = changeCoinsTopDown(coins, n-coins[i], dp);
            minCoinsRequired = min(minCoinsRequired, curr+1);
        }
    }
    return dp[n] = minCoinsRequired;
}

int changeCoinsBottomUp(vector<int> coins, int n){
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<coins.size(); j++) {
            if(coins[j] <= i){
                int curr = dp[i-coins[j]];
                dp[i] = min(dp[i], curr+1);
            }
        }
    }
    return dp[n];
}

int main() {
    vector<int> coins = {1,2,5};
    int n = 11, l = coins.size();
    vector<int> dp(n+1, -1);

    cout << changeCoins(coins, l, n) << endl;
    cout << changeCoinsTopDown(coins, n, dp) << endl;
    cout << changeCoinsBottomUp(coins, n) << endl;

    return 0;
}