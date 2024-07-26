// s = "abcabcaa" p = "a?c*?a*"
// s = "abcabc" p = "a?b*"

#include<iostream>
#include<vector>
using namespace std;

bool wildCardMatching(string s, string p, int m, int n, int i, int j) {
    // base case
    if(i == m) {
        for(int k=j; k<n; k++)
            if(p[k] != '*')
                return false;
            
        return true;
    }

    if(j == n)
        return false;

    // recursive case
    if(s[i] == p[j] || p[j] == '?')
        return wildCardMatching(s, p, m, n, i+1, j+1);

    if(p[j] == '*')
        return wildCardMatching(s, p, m, n, i+1, j) || wildCardMatching(s, p, m, n, i, j+1);

    return false;
}

bool wildCardMatchingTopDown(string s, string p, int m, int n, int i, int j, vector<vector<int>> &dp) {
    // look up
    if(dp[i][j] != -1)
        return dp[i][j];

    // base case
    if(i == m) {
        for(int k=j; k<n; k++)
            if(p[k] != '*')
                return dp[i][j] = false;
            
        return dp[i][j] = true;
    }

    if(j == n)
        return dp[i][j] = false;

    // recursive case
    if(s[i] == p[j] || p[j] == '?')
        return dp[i][j] = wildCardMatchingTopDown(s, p, m, n, i+1, j+1, dp);

    else if(p[j] == '*')
        return dp[i][j] = wildCardMatchingTopDown(s, p, m, n, i+1, j, dp) || wildCardMatchingTopDown(s, p, m, n, i, j+1, dp);

    return dp[i][j] = false;
}

int wildCardMatchingBottomUp(string s, string p, int m, int n) {
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

    for(int j=0; j<=n; j++){
        bool flag = true;
        for(int k=j; k<n; k++) {
            if(p[k] != '*') {
                flag = false;
                break;
            }
        }
        dp[m][j] = flag;
    }

    for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            if(s[i] == p[j] || p[j] == '?')
                dp[i][j] = dp[i+1][j+1];

            else if(p[j] == '*')
                dp[i][j] = dp[i+1][j] || dp[i][j+1];

            else
                dp[i][j] = false;
        }
    }
    return dp[0][0];
}

int main() {
    string s = "abcabcaa";
    string p = "a?c*?a*";

    int m = s.length();
    int n = p.length();

    cout << wildCardMatching(s, p, m, n, 0, 0) << endl;

    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    cout << wildCardMatchingTopDown(s, p, m, n, 0, 0, dp) << endl;

    cout << wildCardMatchingBottomUp(s, p, m, n) << endl;

    return 0;
}