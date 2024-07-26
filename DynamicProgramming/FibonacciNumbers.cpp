#include<iostream>
#include<vector>
using namespace std;

int count1 = 0;
int nthFibNumber(int n) {
    count1++;
    // base case
    if(n == 0 || n == 1)
        return n;

    // recursive case
    return nthFibNumber(n-1) + nthFibNumber(n-2);
}

int count2 = 0;
int nthFibNumberTopDown(int n, vector<int> &dp) {
    count2++;
    // lookup
    if(dp[n] != -1)
        return dp[n];

    // base case
    if(n == 0 || n == 1)
        return dp[n] = n;

    // recursive case
    dp[n] = nthFibNumberTopDown(n-1, dp) + nthFibNumberTopDown(n-2, dp);
    return dp[n];
}

int nthFibNumberBottomUp(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int nthFibNumberBottomUpSpaceOptimized(int n) {
    if (n == 0 || n == 1) 
        return n;

    int first = 0, second = 1, ans = 0;

    for(int i=2; i<=n; i++) {
        ans = first + second;
        first = second;
        second = ans;
    }

    return ans;
}

int main() {
    int n = 15;
    vector<int> dp(n+1, -1);
    cout << nthFibNumber(n) << " " << count1 << endl;
    cout << nthFibNumberTopDown(n, dp) << " " << count2  << endl;
    cout << nthFibNumberBottomUp(n) << endl;
    cout << nthFibNumberBottomUpSpaceOptimized(n) << endl;

    return 0;
}