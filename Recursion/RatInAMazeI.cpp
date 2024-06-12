#include<iostream>
using namespace std;

bool checkPath(char maze[][10], int m, int n, int i, int j) {
    // base case
    if(maze[i][j] == 'X')
        return false;

    if(i == m-1 && j == n-1)
        return true;

    // recursive case
    if(j == n-1) {
        return checkPath(maze, m, n, i+1, j);
    } else if(i == m-1) {
        return checkPath(maze, m, n, i, j+1);
    } else{
        return checkPath(maze, m, n, i+1, j) || checkPath(maze, m, n, i, j+1);
    }
}

int main() {

	char maze[][10] = {
		"0000",
		"0XX0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	checkPath(maze, m, n, 0, 0) ? cout << "path exists" << endl : cout << "path does not exist" << endl;

	return 0;
}