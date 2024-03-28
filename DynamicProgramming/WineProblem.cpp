#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices, int n, int i, int j, int y){
    // base case
    if(i == j)
        return prices[i] * y;

    // recursive case
    return max(y*prices[i] + maxProfit(prices, n, i+1, j, y+1), 
                y*prices[j] + maxProfit(prices, n, i, j-1, y+1));
}

int maxProfitTopDown(vector<int> prices, int n, int i, int j, int y, vector<vector<int>>& dp) {
    // look up
    if(dp[i][j] != -1)
        return dp[i][j];

    // base case
    if(i == j)
        return dp[i][j] = prices[i] * y;

    // recursive case
    return dp[i][j] = max(y*prices[i] + maxProfitTopDown(prices, n, i+1, j, y+1, dp), 
                        y*prices[j] + maxProfitTopDown(prices, n, i, j-1, y+1, dp));
}

int maxProfitBottomUp(vector<int> prices, int n) {
    vector<vector<int>> dp(n, vector<int> (n));

    for(int i=0; i<n; i++){
        int y = n;
        dp[i][i] = prices[i] * y;
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            int y = n - j + i;
            dp[i][j] = max(y*prices[i] + dp[i+1][j], y*prices[j] + dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}

int main() {
    vector<int> prices = {2, 3, 5, 1, 4};
	int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << maxProfit(prices, n, 0, n-1, 1) << endl;
    cout << maxProfitTopDown(prices, n, 0, n-1, 1, dp) << endl;
    cout << maxProfitBottomUp(prices, n) << endl;

    return 0;
}