#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSteps(vector<int> vec, int i, int j) {
    // base case
    if(i == j)
        return 0;

    // recursive case
    int minSoFar = INT_MAX, count = 0;

    for(int k = i; k < j; k++) {
        count = minSteps(vec, i, k) + minSteps(vec, k+1, j) + vec[i-1]*vec[k]*vec[j];

        minSoFar = min(minSoFar, count);
    }
    return minSoFar;
}

int minStepsTopDown(vector<int> vec, int i, int j, vector<vector<int>> &dp) {
    // look up
    if(dp[i][j] != -1)
        return dp[i][j];

    // base case
    if(i == j)
        return dp[i][j] = 0;

    // recursive case
    int minSoFar = INT_MAX, count = 0;

    for(int k = i; k < j; k++) {
        count = minStepsTopDown(vec, i, k, dp) + minStepsTopDown(vec, k+1, j, dp) + vec[i-1]*vec[k]*vec[j];

        minSoFar = min(minSoFar, count);
    }
    return dp[i][j] = minSoFar;
}

int minStepsBottomUp(vector<int> vec, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int l = 2; l < n; l++) {
        for(int i = 1; i < n-l+1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + vec[i-1] * vec[k] * vec[j]);
        }
    }
    return dp[1][n-1];
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 3};
    int n = vec.size();

    cout << minSteps(vec, 1, n-1) << endl;

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout << minStepsTopDown(vec, 1, n-1, dp) << endl;

    cout << minStepsBottomUp(vec, n) << endl;
}