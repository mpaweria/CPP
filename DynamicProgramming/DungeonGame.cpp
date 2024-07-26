#include<iostream>
#include<vector>
using namespace std;

int minEnergy(vector<vector<int>> dungeon, int m, int n, int i, int j) {
    // base case
    if(i == m-1 && j == n-1)
        return dungeon[i][j] <= 0 ? -dungeon[i][j] +  1 : 1;

    // recursive case
    if(i == m-1)
        return max(1, minEnergy(dungeon, m, n, i, j+1) - dungeon[i][j]);

    if(j == n-1)
        return max(1, minEnergy(dungeon, m ,n, i+1, j) - dungeon[i][j]);

    int right = minEnergy(dungeon, m, n, i, j+1);
    int down = minEnergy(dungeon, m ,n, i+1, j);

    int minHealth = min(right, down) - dungeon[i][j];

    return minHealth <= 0 ? 1 : minHealth;
}

int minEnergyTopDown(vector<vector<int>> dungeon, int m, int n, int i, int j, vector<vector<int>>& dp) {
    // look up
    if(dp[i][j] != -1)
        return dp[i][j];

    // base case
    if(i == m-1 && j == n-1)
        return dp[i][j] = dungeon[i][j] <= 0 ? -dungeon[i][j] +  1 : 1;

    // recursive case
    if(i == m-1)
        return dp[i][j] = max(1, minEnergyTopDown(dungeon, m, n, i, j+1, dp) - dungeon[i][j]);

    if(j == n-1)
        return dp[i][j] = max(1, minEnergyTopDown(dungeon, m ,n, i+1, j, dp) - dungeon[i][j]);

    int right = minEnergyTopDown(dungeon, m, n, i, j+1, dp);
    int down = minEnergyTopDown(dungeon, m ,n, i+1, j, dp);

    int minHealth = min(right, down) - dungeon[i][j];

    return dp[i][j] = minHealth <= 0 ? 1 : minHealth;
}

int minEnergyBottomUp(vector<vector<int>> dungeon, int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));

    for(int i = m-1; i>=0; i--) {
        for(int j = n-1; j>=0; j--) {
            if(i == m-1 && j == n-1)
                dp[i][j] = dungeon[i][j] <= 0 ? -dungeon[i][j] +  1 : 1;
            else if(i == m-1)
                dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
            else if(j == n-1)
                dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
            else {
                dp[i][j] = max(1, min(dp[i][j+1] - dungeon[i][j], dp[i+1][j] - dungeon[i][j]));
            }
        }
    }
    return dp[0][0];
}

int minEnergyBottomUpSpaceOptimized(vector<vector<int>> dungeon, int m, int n) {
    vector<int> dp(n);

    for(int i = m-1; i>=0; i--) {
        for(int j = n-1; j>=0; j--) {
            if(i == m-1 && j == n-1)
                dp[j] = dungeon[i][j] <= 0 ? -dungeon[i][j] +  1 : 1;
            else if(i == m-1)
                dp[j] = max(1, dp[j+1] - dungeon[i][j]);
            else if(j == n-1)
                dp[j] = max(1, dp[j] - dungeon[i][j]);
            else {
                dp[j] = max(1, min(dp[j+1] - dungeon[i][j], dp[j] - dungeon[i][j]));
            }
        }
    }
    return dp[0];
}

int main() {
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    int m = dungeon.size(), n = dungeon[0].size();

    cout << minEnergy(dungeon, m, n, 0, 0) << endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << minEnergyTopDown(dungeon, m, n, 0, 0, dp) << endl;

    cout << minEnergyBottomUp(dungeon, m, n) << endl;

    cout << minEnergyBottomUpSpaceOptimized(dungeon, m, n) << endl;

    return 0;
}