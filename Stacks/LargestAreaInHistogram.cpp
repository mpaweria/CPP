#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nearestSmallerLeft(int A[], int n) {
    stack<int> s;
    vector<int> vec;

    for(int i=0; i<n; i++) {
        while (!s.empty() && A[s.top()] >= A[i])
        {
            s.pop();
        }
        if (s.empty())
            vec.push_back(-1);
        else
            vec.push_back(s.top());
        s.push(i);
    }
    return vec;
}

vector<int> nearestSmallerRight(int A[], int n) {
    stack<int> s;
    vector<int> vec;

    for(int i=n-1; i>=0; i--) {
        while (!s.empty() && A[s.top()] >= A[i])
        {
            s.pop();
        }
        if(s.empty())
            vec.push_back(n);
        else
            vec.push_back(s.top());
        s.push(i);
    }
    reverse(vec.begin(), vec.end());

    return vec;
}

int main() {

	// time : 3n steps ~ O(n)
	// space: O(n)

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	// 1. for each element in h[], find the index of nearest smaller element to the right
	vector<int> nsr = nearestSmallerRight(h, n);

	// 2. for each element in h[], find the index of nearest smaaller element to the left
	vector<int> nsl = nearestSmallerLeft(h, n);

	// 3. find the area of the largest rectangle in the histogram
	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		// find the area of the largest rectangle whose height is h[i]
		int bestWidth = (nsr[i] - nsl[i]) - 1;
		int bestArea = h[i] * bestWidth;
		maxArea = max(maxArea, bestArea);
	}

	cout << maxArea << endl;

	return 0;
}