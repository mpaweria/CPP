#include<iostream>
#include<vector>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool searchWord(vector<vector<char>>& board, string word, int m, int n, int i, int j, int k) {
    // base case
    if(k == word.size()){
        // cout << board[i][j] << " k ";
        return true;
    }

    if(i == -1 || i == m || j == -1 || j == n) {        
        // cout << board[i][j] << " ";
        return false;
    }

    if(board[i][j] != word[k]) {
        // cout << board[i][j] << " ";
        return false;
    }

    // recrusive case
    board[i][j] = '#';
    for(int l=0; l<4; l++) {
        if(searchWord(board, word, m, n, i+dx[l], j+dy[l], k+1))
            return true;
    }
    board[i][j] = word[k];

    return false;
}

bool exists(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == word[0]) {
                if(searchWord(board, word, m, n, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}

int main() {

	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};

	string word = "ABCESC";

	exists(board, word) ? cout << "true" << endl :
	                          cout << "false" << endl;

	return 0;
}