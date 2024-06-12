#include<iostream>
using namespace std;

int countPaths(char maze[][10], int m, int n, int i, int j) {
    // base case
    if(maze[i][j] == 'X')
        return 0;

    if(i == m-1 && j == n-1)
        return 1;

    // recursive case
    if(j == n-1) {
        return countPaths(maze, m, n, i+1, j);
    } else if(i == m-1) {
        return countPaths(maze, m, n, i, j+1);
    } else{
        return countPaths(maze, m, n, i+1, j) + countPaths(maze, m, n, i, j+1);
    }
}

int main() {

	char maze[][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	cout << countPaths(maze, m, n, 0, 0) << endl;

	return 0;
}