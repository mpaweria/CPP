#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(vector<int> prices, int n, int i, int k) {
    // base case
    if(i == n || k == 0)
        return 0;

    // recursive case
    int doNotBuy = maxProfit(prices, n, i+1, k);

    int buyProfitSoFar = INT_MIN;
    for(int j=i+1; j < n; j++) {
        buyProfitSoFar = max(buyProfitSoFar, prices[j] - prices[i] + maxProfit(prices, n, j+1, k-1));
    }

    return max(doNotBuy, buyProfitSoFar);
}

int maxProfitTopDown(vector<int> prices, int n, int i, int k, vector<vector<int>> &dp) {
    // look up
    if(dp[i][k] != -1)
        return dp[i][k];

    // base case
    if(i == n || k == 0)
        return dp[i][k] = 0;

    // recursive case
    int doNotBuy = maxProfitTopDown(prices, n, i+1, k, dp);

    int buyProfitSoFar = INT_MIN;
    for(int j=i+1; j < n; j++) {
        buyProfitSoFar = max(buyProfitSoFar, prices[j] - prices[i] + maxProfitTopDown(prices, n, j+1, k-1, dp));
    }

    return dp[i][k] = max(doNotBuy, buyProfitSoFar);
}

int maxProfitBottomUp(vector<int> prices, int n, int K) {
    vector<vector<int>> dp(n+1, vector<int>(K+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int k = 1; k <= K; k++) {
            int doNotBuy = dp[i+1][k];
            int buyProfitSoFar = INT_MIN;
            for(int j=i+1; j < n; j++) {
                buyProfitSoFar = max(buyProfitSoFar, prices[j] - prices[i] + dp[j+1][k-1]);
            }
            dp[i][k] = max(doNotBuy, buyProfitSoFar);
        }
    }
    return dp[0][K];
}

int main() {
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2, n = prices.size();

    cout << maxProfit(prices, n, 0, k) << endl;

    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    cout << maxProfitTopDown(prices, n, 0, k, dp) << endl;

    cout << maxProfitBottomUp(prices, n, k) << endl;

    return 0;
}