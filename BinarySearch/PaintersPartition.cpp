#include<iostream>
#include<climits>
using namespace std;

int minPainterRequired(int n, int boards[], int m) {
    int minPainter = 1, time = 0, i = 0;
    while (i < n)
    {
        time += boards[i];
        if(time > m) {
            minPainter++;
            time = 0;
            continue;
        }
        i++;
    }
    return minPainter;
}

int minTimeRequired(int n, int k, int boards[]) {
    int s = 0, e = 0, ans = 0;
    for(int i=0; i<n; i++) {
        s = max(s, boards[i]);
        e += boards[i];
    }

    while (s <= e)
    {
        int m = s + (e - s)/2;
        int x = minPainterRequired(n, boards, m);
        if(x <= k) {
            ans = m;
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return ans;
}

int main() {
    int n = 5;
	int k = 3;
	int boards[] = {1, 3, 5, 2, 4};
	cout << minTimeRequired(n, k, boards) << endl;

	return 0;
}