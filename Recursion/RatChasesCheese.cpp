#include<iostream>
using namespace std;

void printPath(char maze[][10], char path[][10], int m, int n, int i, int j) {
    // base case
    if(i == -1 || j == -1 || i == m || j == n)
        return;

    if(maze[i][j] == 'X')
        return;

    if(i == m-1 && j == n-1)
    {
        path[i][j] = '1';

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        path[i][j] = '0';
        return;
    }

    // recursive case
    path[i][j] = '1';
    maze[i][j] = 'X';
    printPath(maze, path, m, n, i, j+1);
    printPath(maze, path, m, n, i, j-1);
    printPath(maze, path, m, n, i+1, j);
    printPath(maze, path, m, n, i-1, j);
    path[i][j] = '0';
    maze[i][j] = '0';
}

int main() {

	char maze[][10] = {
		"0X00",
		"000X",
		"X0X0",
		"X00X",
		"XX00"
	};

	char path[][10] = {
		"0000",
		"0000",
		"0000",
		"0000",
		"0000"
	};

	int m = 5;
	int n = 4;

	printPath(maze, path, m, n, 0, 0);

	return 0;
}