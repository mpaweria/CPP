#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int LIS(vector<int> vec, int n, int i) {
    // base case
    if(i == n)
        return 0;

    // recursive case
    int maxSoFar = INT_MIN;
    for(int j=i+1; j<n; j++) {
        if(vec[j] >= vec[i])
            maxSoFar = max(maxSoFar, LIS(vec, n, j));
    }
    return maxSoFar == INT_MIN ? 1 : 1 + maxSoFar;
}

int LISBottomUp(vector<int> vec, int n) {
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0; i--) {
        int maxSoFar = INT_MIN;
        for(int j=i+1; j<n; j++) {
            if(vec[j] >= vec[i])
                maxSoFar = max(maxSoFar, dp[j]);
        }
        dp[i] = maxSoFar == INT_MIN ? 1 : 1 + maxSoFar;
    }
    return dp[0];
}

int main() {
    vector<int> vec = {1, 2, 5, 3, 0, 4, 6};
    int n = 7;

    int maxSoFar = 0;
    for(int i=0; i<n; i++) {
        maxSoFar = max(maxSoFar, LIS(vec, n, i));
    }
    cout << maxSoFar << endl;

    cout << LISBottomUp(vec, n) << endl;

    return 0;
}