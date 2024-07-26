#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int M = 1e9 + 7;

long long dial(int cell, int n, unordered_map<int, vector<int>> pos) {
    // base case
    if(n == 0)
        return 1;

    // recursive case
    int ans = 0;
    for(int nextCell : pos[cell]) {
        ans = (ans + dial(nextCell, n-1, pos)) % M;
    }

    return ans;
}

long long dialTopDown(int cell, int n, unordered_map<int, vector<int>> pos, vector<vector<int>> &dp) {
    // look up
    if(dp[n][cell] != -1)
        return dp[n][cell];

    // base case
    if(n == 0)
        return dp[n][cell] = 1;

    // recursive case
    int ans = 0;
    for(int nextCell : pos[cell]) {
        ans = (ans + dialTopDown(nextCell, n-1, pos, dp)) % M;
    }

    return dp[n][cell] = ans;
}

long long dialBottomUp(int n, unordered_map<int, vector<int>> pos) {
    vector<vector<int>> dp(n, vector<int>(10));

    for(int j=0; j<10; j++)
        dp[0][j] = 1;

    for(int i=1; i<n; i++) {
        for(int j=0; j<10; j++) {
            int ans = 0;
            for(int &val: pos[j]) {
                ans = (ans + dp[i-1][val]) % M;
            }
            dp[i][j] = ans;
        }
    }

    int result=0;
    for (int i=0; i<10; i++){
        result = (result + dp[n-1][i]) % M;
    }

    return result;
}

int knightDialer(int n) {
    unordered_map<int, vector<int>> pos;
    pos[0] = {4,6};
    pos[1] = {6,8};
    pos[2] = {7,9};
    pos[3] = {4,8};
    pos[4] = {0,3,9};
    pos[5] = {};
    pos[6] = {0,1,7};
    pos[7] = {2,6};
    pos[8] = {1,3};
    pos[9] = {2,4};

    long long result = 0;

    // for(int i=0; i<10; i++) {
    //     result = (result + dial(i, n-1, pos)) % M;
    // }

    vector<vector<int>> dp(n+1, vector<int>(10, -1));
    // for(int i=0; i<10; i++) {
    //     result = (result + dialTopDown(i, n-1, pos, dp)) % M;
    // }

    result = dialBottomUp(n, pos);

    return result;
}

int main() {
    int n = 2;

    cout << knightDialer(n); 

    return 0;
}