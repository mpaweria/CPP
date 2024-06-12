#include<iostream>
using namespace std;

void printPaths(char maze[][10], char path[][10], int m, int n, int i, int j) {
    // base case
    if(i == m || j == n)
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
    printPaths(maze, path, m, n, i+1, j);
    printPaths(maze, path, m, n, i, j+1);
    path[i][j] = '0';
}

int main() {

	char maze[][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

    char path[][10] = {
		"0000",
		"0000",
		"0000",
		"0000"
	};

	int m = 4;
	int n = 4;

	printPaths(maze,path, m, n, 0, 0);

	return 0;
}