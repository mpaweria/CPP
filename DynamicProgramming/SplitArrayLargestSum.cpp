#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int arraySum(vector<int> vec, int n, int k, int i) {
    // base case
    // if(i == n) {
    //     if(k == 0)
    //         return 0;
    //     return INT_MAX;
    // }

    if(k == 0) {
        if(i == n)
            return 0;
        return INT_MAX;
    }

    // recursive case
    int ans = INT_MAX, sum = 0;

    for(int j = i; j <= n-k; j++) {
        sum += vec[j];
        ans = min(ans, max(sum, arraySum(vec, n, k-1, j+1)));
    }
    return ans;
}

int arraySumTopDown(vector<int> vec, int n, int k, int i, vector<vector<int>> &dp) {
    // look up
    if(dp[i][k] != -1)
        return dp[i][k];

    // base case
    if(k == 0) {
        if(i == n)
            return dp[i][k] = 0;
        return dp[i][k] = INT_MAX;
    }

    // recursive case
    int ans = INT_MAX, sum = 0;

    for(int j = i; j <= n-k; j++) {
        sum += vec[j];
        ans = min(ans, max(sum, arraySumTopDown(vec, n, k-1, j+1, dp)));
    }
    return dp[i][k] = ans;
}

int arraySumBottomUp(vector<int> vec, int n, int K) {
    vector<vector<int>> dp(n+1, vector<int>(K+1, INT_MAX));
    dp[n][0] = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int k = 1; k <= K; k++) {
            int ans = INT_MAX, sum = 0;
            for(int j = i; j <= n-k; j++) {
                sum += vec[j];
                if(dp[j+1][k-1] != INT_MAX)
                    ans = min(ans, max(sum, dp[j+1][k-1]));
            }
            dp[i][k] = ans;
        }
    }
    return dp[0][K];
}

int main() {
    vector<int> vec = {7, 2, 5, 10, 8};
    int k = 2, n = vec.size();

    cout << arraySum(vec, n, k, 0) << endl;

    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    cout << arraySumTopDown(vec, n, k, 0, dp) << endl;

    cout << arraySumBottomUp(vec, n, k) << endl;
}