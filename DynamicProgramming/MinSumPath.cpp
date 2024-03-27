#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int>> grid, int i, int j, int m, int n) {
    // base case
    if(i==m-1 && j==n-1)
        return grid[i][j];

    // recursive case
    if(i==m-1)
        return grid[i][j] + minPathSum(grid, i, j+1, m, n);

    if(j==n-1)
        return grid[i][j] + minPathSum(grid, i+1, j, m, n);
    
    return grid[i][j] + min(minPathSum(grid, i+1, j, m, n), minPathSum(grid, i, j+1, m, n));
}

int minPathSumTopDown(vector<vector<int>> grid, int i, int j, int m, int n, vector<vector<int>>& dp) {
    // look up
    if(dp[i][j] != -1)
        return dp[i][j];

    // base case
    if(i==m-1 && j==n-1)
        return dp[i][j] = grid[i][j];

    // recursive case
    if(i==m-1)
        return dp[i][j] = grid[i][j] + minPathSum(grid, i, j+1, m, n);

    if(j==n-1)
        return dp[i][j] = grid[i][j] + minPathSum(grid, i+1, j, m, n);
    
    return dp[i][j] = grid[i][j] + min(minPathSum(grid, i+1, j, m, n), minPathSum(grid, i, j+1, m, n));
}

int minPathSumBottomUp(vector<vector<int>> grid, int i, int j, int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));

    for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            if(i==m-1 && j==n-1)
                dp[i][j] = grid[i][j];
            else {
                if(i==m-1)
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                else if(j==n-1)
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                else 
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}

int minPathSumBottomUpSpaceOptimized(vector<vector<int>> grid, int i, int j, int m, int n) {
    vector<int> dp(n);

    for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            if(i==m-1 && j==n-1)
                dp[j] = grid[i][j];
            else {
                if(i==m-1)
                    dp[j] = grid[i][j] + dp[j+1];
                else if(j==n-1)
                    dp[j] = grid[i][j] + dp[j];
                else 
                    dp[j] = grid[i][j] + min(dp[j+1], dp[j]);
            }
        }
    }
    return dp[0];
}

int main() {
    vector<vector<int>> grid = {
                                {1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}
                            };

    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));

    cout << minPathSum(grid, 0, 0, m, n) << endl;
    cout << minPathSumTopDown(grid, 0, 0, m, n, dp) << endl;
    cout << minPathSumBottomUp(grid, 0, 0, m, n) << endl;    
    cout << minPathSumBottomUpSpaceOptimized(grid, 0, 0, m, n) << endl;

    return 0;
}