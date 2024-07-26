#include<iostream>
#include<vector>
using namespace std;

int maxPrice(vector<int> profits, vector<int> weights, int n, int i, int w) {
    // base case
    if (i == n)
        return 0;

    if (w == 0)
        return 0;

    // recursive case
    if(weights[i] > w)
        return maxPrice(profits, weights, n, i+1, w);

    return max(maxPrice(profits, weights, n, i+1, w), profits[i] + maxPrice(profits, weights, n, i, w-weights[i]));
}

int maxPriceTopDown(vector<int> profits, vector<int> weights, int n, int i, int w, vector<vector<int>> &dp) {
    // look up
    if(dp[i][w] != -1)
        return dp[i][w];

    // base case
    if (i == n)
        return dp[i][w] = 0;

    if (w == 0)
        return dp[i][w] = 0;

    // recursive case
    if(weights[i] > w)
        return dp[i][w] = maxPriceTopDown(profits, weights, n, i+1, w, dp);

    return dp[i][w] = max(maxPriceTopDown(profits, weights, n, i+1, w, dp), profits[i] + maxPriceTopDown(profits, weights, n, i, w-weights[i], dp));
}

int maxPriceBottomUp(vector<int> profits, vector<int> weights, int n, int w) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = 1; j <= w; j++) {
            if(weights[i] > j)
                dp[i][j] = dp[i+1][j];
            else
                dp[i][j] = max(dp[i+1][j], profits[i] + dp[i][j-weights[i]]);
        }
    }
    return dp[0][w];
}

int maxPriceBottomUpSpaceOptimized(vector<int> profits, vector<int> weights, int n, int w) {
    vector<int> dp(w+1, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= w; j++) {
            if(weights[i] <= j)
                dp[j] = max(dp[j], profits[i] + dp[j-weights[i]]);
        }
    }
    return dp[w];
}

int main() {
    int n = 4;
	int w = 8;
	vector<int> profits = {10, 40, 50, 70};
	vector<int> weights = {1, 3, 4, 5};

    cout << maxPrice(profits, weights, n, 0, w) << endl;

    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    cout << maxPriceTopDown(profits, weights, n, 0, w, dp) << endl;

    cout << maxPriceBottomUp(profits, weights, n, w) << endl;

    cout << maxPriceBottomUpSpaceOptimized(profits, weights, n, w) << endl;

    return 0;
}