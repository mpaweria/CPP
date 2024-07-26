#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isPalindrome(string str) {
    int i = 0, j = str.length()-1;
    while (i < j)
    {
        if(str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int countPalindromePartition(string str, int n, int i) {
    // base case
    if(i == n)
        return 1;

    // recursive case
    int count = 0;
    
    for(int j = i; j < n; j++) {
        string substr = str.substr(i, j-i+1);
        if(isPalindrome(substr)) {
            count += countPalindromePartition(str, n, j+1);
        }
    }
    return count;
}

int countPalindromePartitionTopDown(string str, int n, int i, vector<int> &dp) {
    // look up
    if(dp[i] != -1)
        return dp[i];

    // base case
    if(i == n)
        return dp[i] = 1;

    // recursive case
    int count = 0;
    
    for(int j = i; j < n; j++) {
        string substr = str.substr(i, j-i+1);
        if(isPalindrome(substr)) {
            count += countPalindromePartitionTopDown(str, n, j+1, dp);
        }
    }
    return dp[i] = count;
}

// Time: O(n^3)
int countPalindromePartitionBottomUp(string str, int n) {
    vector<int> dp(n+1);
    dp[n] = 1;

    for(int i=n-1; i>=0; i--) {
        int count = 0;    
        for(int j = i; j < n; j++) {
            string substr = str.substr(i, j-i+1);
            if(isPalindrome(substr)) {
                count += dp[j+1];
            }
        }
        dp[i] = count;
    }
    return dp[0];
}

// Time: O(n^2)
int countPalindromePartitionBottomUpSpaceOptimized(string str, int n) {
    vector<vector<bool>> memo(n, vector<bool>(n));

    for(int i = 0; i < n; i++) {
        memo[i][i] = true;
    }

    for(int i = 0; i < n-1; i++){
        memo[i][i+1] = str[i] == str[i+1] ? true : false;
    }

    for(int i = n-3; i >= 0; i--) {
        for(int j = i+2; j < n; j++) {
            memo[i][j] = str[i] == str[j] && memo[i+1][j-1];
        }
    }

    vector<int> dp(n+1);
    dp[n] = 1;

    for(int i=n-1; i>=0; i--) {
        int count = 0;    
        for(int j = i; j < n; j++) {
            if(memo[i][j]) {
                count += dp[j+1];
            }
        }
        dp[i] = count;
    }
    return dp[0];
}

int main() {
    string str = "abaaaa";
    int n = str.length();

    cout << countPalindromePartition(str, n, 0) << endl;

    vector<int> dp(n+1,-1);
    cout << countPalindromePartitionTopDown(str, n, 0, dp) << endl;

    cout << countPalindromePartitionBottomUp(str, n) << endl;

    cout << countPalindromePartitionBottomUpSpaceOptimized(str, n) << endl;

    return 0;
}