#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices, int i, int j, int y) {
    // base case
    if(i == j)
        return prices[i] * y;

    // recursive case
    int sellFromFront = prices[i] * y + maxProfit(prices, i+1, j, y+1);
    int sellFromLast = prices[j] * y + maxProfit(prices, i, j-1, y+1); 

    return max(sellFromFront, sellFromLast);
}

int maxProfitTopDown(vector<int> prices, int i, int j, int y, vector<vector<int>> &dp) {
    // look up
    if(dp[i][j] != -1)
        return dp[i][j];

    // base case
    if(i == j)
        return dp[i][j] = prices[i] * y;

    // recursive case
    int sellFromFront = prices[i] * y + maxProfitTopDown(prices, i+1, j, y+1, dp);
    int sellFromLast = prices[j] * y + maxProfitTopDown(prices, i, j-1, y+1, dp); 

    return dp[i][j] = max(sellFromFront, sellFromLast);
}

int maxProfitBottomUp(vector<int> prices, int n){
    vector<vector<int>> dp(n, vector<int>(n));

    for(int i=0; i<n; i++)
        dp[i][i] = n * prices[i];

    for(int i = n-2; i >= 0; i--) {
        for(int j = i+1; j <= n-1; j++) {
            int y = n - j + i;
            dp[i][j] = max(y * prices[i] + dp[i+1][j], y * prices[j] + dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}

int main() {
    vector<int> prices = {2, 3, 5, 1, 4};
	int n = prices.size();

    cout << maxProfit(prices, 0, n-1, 1)  << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << maxProfitTopDown(prices, 0, n-1, 1, dp)  << endl;

    cout << maxProfitBottomUp(prices, n);
}