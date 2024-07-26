#include<iostream>
#include<vector>
using namespace std;

int maxPrice(vector<int> profits, vector<int> weights, int n, int i, int w) {
    // base case
    if(i == n)
        return 0;

    if(w == 0)
        return 0;

    // recursive case
    if(weights[i] <= w) {
        return max((profits[i] + maxPrice(profits, weights, n, i+1, w-weights[i])), maxPrice(profits, weights, n, i+1, w));
    }
    return maxPrice(profits, weights, n, i+1, w);
}

int maxPriceTopDown(vector<int> profits, vector<int> weights, int n, int i, int w, vector<vector<int>> &dp) {
    // look up
    if(dp[i][w] != -1)
        return dp[i][w];

    // base case
    if(i == n)
        return dp[i][w] = 0;

    if(w == 0)
        return dp[i][w] = 0;

    // recursive case
    if(weights[i] <= w) {
        return dp[i][w] = max((profits[i] + maxPriceTopDown(profits, weights, n, i+1, w-weights[i], dp)), maxPriceTopDown(profits, weights, n, i+1, w, dp));
    }
    return dp[i][w] = maxPriceTopDown(profits, weights, n, i+1, w, dp);
}

int maxPriceBottomUp(vector<int> profits, vector<int> weights, int n, int w) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = 1; j <= w; j++) {
            if(weights[i] <= j) {
                dp[i][j] = max((profits[i] + dp[i+1][j-weights[i]]), dp[i+1][j]);
            } else {
                dp[i][j] = dp[i+1][j];
            }
        }
    }
    return dp[0][w];
}

int maxPriceBottomUpSpaceOptimized(vector<int> profits, vector<int> weights, int n, int w) {
    vector<int> dp(w+1, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int j = w; j >= 1; j--) {
            if(weights[i] <= j) {
                dp[j] = max((profits[i] + dp[j-weights[i]]), dp[j]);
            } else {
                dp[j] = dp[j];
            }
        }
    }
    return dp[w];
}

int main() {
    int n = 5;
	int w = 4;
	vector<int> weights = {1, 2, 3, 2, 2};
	vector<int> profits = {8, 4, 1, 5, 3};

    cout << maxPrice(profits, weights, n, 0, w) << endl;

    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    cout << maxPriceTopDown(profits, weights, n, 0, w, dp) << endl;

    cout << maxPriceBottomUp(profits, weights, n, w) << endl;

    cout << maxPriceBottomUpSpaceOptimized(profits, weights, n, w) << endl;

    return 0;
}