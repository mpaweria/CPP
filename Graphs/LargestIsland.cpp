#include<iostream>
#include<vector>

using namespace std;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};

int dfsHelper(vector<vector<int>> grid, vector<vector<bool>> &visited, int m, int n, int i, int j) {
    visited[i][j] = true;
    int count = 1;

    for(int k=0; k<4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
            count += dfsHelper(grid, visited, m, n, nx, ny);
        }
    }
    return count;
}

int largestIsland(vector<vector<int>> grid, int m, int n) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int maxArea = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                maxArea = max(maxArea, dfsHelper(grid, visited, m, n, i, j));
            }
        }
    }
    return maxArea;
}

int main() {

	vector<vector<int>> grid = {{1, 0, 0, 1, 0},
		                        {1, 0, 1, 0, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 0, 1, 1, 1}};

	int m = grid.size();
	int n = grid[0].size();

	cout << largestIsland(grid, m, n) << endl;

	return 0;
}