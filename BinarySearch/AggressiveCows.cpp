#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

bool canPlaceCow(int c, int n, int pos[], int m) {
    int cowsPlaced = 1, lastPos = pos[0];

    for(int i=1; i<n; i++) {
        if(pos[i]-lastPos >= m) {
            cowsPlaced++;
            lastPos = pos[i];

            if(cowsPlaced == c)
                return true;
        }
    }
    return false;
}

int largestMinDist(int n, int c, int pos[]) {
    int s = INT_MAX, e = pos[n-1]-pos[0], ans = 0;
    for(int i=1; i<n; i++) {
        if(pos[i]-pos[i-1] < s)
            s = pos[i]-pos[i-1];
    }

    while(s <= e) {
        int m = s + (e - s)/2;
        if(canPlaceCow(c, n, pos, m)) {
            ans = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return ans;
}

int main() {
    int n = 5;
	int c = 3;
	int pos[] = {1, 2, 4, 8, 9};
    sort(pos, pos + n);
	cout << largestMinDist(n, c, pos) << endl;

	return 0;
}