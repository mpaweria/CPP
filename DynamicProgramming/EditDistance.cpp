/*

=============
Edit Distance
=============

Given two strings s1 and s2, return the min. no. of edit operations required to convert
s1 to s2.

You have the following three operations permitted on a word:

	> Insert a character
	> Delete a character
	> Replace a character

The min. no. of edits required to convert s1 to s2 is also known as the edit distance
between s1 & s2.

Examples

Example 1:

	Input: s1 = "food", s2 = "money"
	Output: 4

Example 2:

	Input: s1 = "horse", s2 = "ros"
	Output: 3

	Explanation:
	horse -> rorse (replace 'h' with 'r')
	rorse -> rose (remove 'r')
	rose -> ros (remove 'e')

Example 3:

	Input: s1 = "intention", s2 = "execution"
	Output: 5

	Explanation:
	intention -> inention (remove 't')
	inention -> enention (replace 'i' with 'e')
	enention -> exention (replace 'n' with 'x')
	exention -> exection (replace 'n' with 'c')
	exection -> execution (insert 'u')

*/

#include<iostream>
#include<vector>

using namespace std;

int editDistance(string s1, string s2, int m, int n, int i, int j) {
    // base case
    if(i == m && j == n)
        return 0;
    
    if(i == m)
        return n-j;

    if(j == n)
        return m-i;

    // recursive case
    if(s1[i] == s2[j])
        return editDistance(s1, s2, m, n, i+1, j+1);
    
    return 1 + min(editDistance(s1, s2, m, n, i, j+1), min(editDistance(s1, s2, m, n, i+1, j), editDistance(s1, s2, m, n, i+1, j+1)));
}

int editDistanceTopDown(string s1, string s2, int m, int n, int i, int j, vector<vector<int>> &dp) {
    // look up
    if(dp[i][j] != -1)
        return dp[i][j];

    // base case
    if(i == m && j == n)
        return dp[i][j] = 0;
    
    if(i == m)
        return dp[i][j] = n-j;

    if(j == n)
        return dp[i][j] = m-i;

    // recursive case
    if(s1[i] == s2[j])
        return dp[i][j] = editDistanceTopDown(s1, s2, m, n, i+1, j+1, dp);
    
    return dp[i][j] = 1 + min(editDistanceTopDown(s1, s2, m, n, i, j+1, dp), min(editDistanceTopDown(s1, s2, m, n, i+1, j, dp), editDistanceTopDown(s1, s2, m, n, i+1, j+1, dp)));
}

int editDistanceBottomUp(string s1, string s2, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int j=0; j<=n; j++)
        dp[m][j] = n-j;

    for(int i=0; i<=m; i++)
        dp[i][n] = m-i;

    for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            dp[i][j] = min(1 + dp[i][j+1], min(1 + dp[i+1][j], int(s1[i]!=s2[j]) + dp[i+1][j+1]));
        }
    }
    return dp[0][0];
}

int main() {

	string s1("horse");
	int m = s1.size();

	string s2("ore");
	int n = s2.size();

    cout << editDistance(s1, s2, m, n, 0, 0) << endl;

    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    cout << editDistanceTopDown(s1, s2, m, n, 0, 0, dp) << endl;

    cout << editDistanceBottomUp(s1, s2, m, n) << endl;

    return 0;
}