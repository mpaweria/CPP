#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> weights, vector<int> profits, int N, int W, int i) {
    // base case
    if(i == N)
        return 0;

    if(W == 0)
        return 0;

    // recursive case
    if(weights[i] > W)
        return maxProfit(weights, profits, N, W, i+1);

    return max(profits[i] + maxProfit(weights, profits, N, W-weights[i], i+1), maxProfit(weights, profits, N, W, i+1));
}

int maxProfitTopDown(vector<int> weights, vector<int> profits, int N, int W, int i, vector<vector<int>> &dp) {
    // look up
    if(dp[i][W] != -1)
        return dp[i][W];
    
    // base case
    if(i == N)
        return dp[i][W] = 0;

    if(W == 0)
        return dp[i][W] = 0;

    // recursive case
    if(weights[i] > W)
        return dp[i][W] = maxProfit(weights, profits, N, W, i+1);

    return dp[i][W] = max(profits[i] + maxProfit(weights, profits, N, W-weights[i], i+1), maxProfit(weights, profits, N, W, i+1));
}

int maxProfitBottomUp(vector<int> weights, vector<int> profits, int N, int W) {
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    
    for(int i=N-1; i>=0; i--) {
        for(int w=1; w<=W; w++) {
            if(weights[i] > w)
                dp[i][w] = dp[i+1][w];
            else {
                dp[i][w] = max(profits[i] + dp[i+1][w - weights[i]], dp[i+1][w]);
            }
        }
    }
    return dp[0][W];
}

int main() {
	int N = 5;
	int W = 4;

	vector<int> weights = {1, 2, 3, 2, 2};
	vector<int> profits = {8, 4, 1, 5, 3};

    vector<vector<int>> dp(N+1, vector<int>(W+1, -1));

    cout << maxProfit(weights, profits, N, W, 0) << endl;
    cout << maxProfitTopDown(weights, profits, N, W, 0, dp) << endl;
    cout << maxProfitBottomUp(weights, profits, N, W) << endl;

    return 0;
}