#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> distMap(m, vector<int>(n, INT_MAX));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 0) {
                q.push({i, j});
                distMap[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int i = front.first;
        int j = front.second;

        for(int k=0; k<4; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];

            if(ii >= 0 && ii < m && jj >= 0 && jj < n && distMap[ii][jj] == INT_MAX) {
                distMap[ii][jj] = distMap[i][j] + 1;
                q.push({ii, jj});
            }
        }
    }
    return distMap;
}

int main() {

	vector<vector<int>> mat = {{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	vector<vector<int>> dist = updateMatrix(mat);

	for (vector<int> row : dist) {
		for (int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}