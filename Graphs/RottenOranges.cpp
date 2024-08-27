// https://leetcode.com/problems/rotting-oranges/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distMap(m, vector<int>(n, INT_MIN));
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    distMap[i][j] = 0;
                }
            }
        }
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();

            int i = front.first;
            int j = front.second;

            for(int k=0; k<4; k++) {
                int ii = i + dx[k];
                int jj = j + dy[k];

                if(ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == 1) {
                    distMap[ii][jj] = distMap[i][j] + 1;
                    grid[ii][jj] = 2;
                    q.push({ii, jj});
                }
            }
        }

        int time = 0;
        int freshFlag = false;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    freshFlag = true;
                    time = -1;
                    break;
                }
                time = max(time, distMap[i][j]);
            }
            if(freshFlag)
                break;
        }
        return time;
    }
};