#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

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

int validSubarrays(int A[], int n) {
    vector<int> v = nearestSmallerRight(A, n);

    int count = 0;
	for (int i = 0; i < v.size(); i++) {
        count += v[i]-i;
	}
    return count;
}

int main() {

	int A[] = {1, 4, 2, 5, 3, 9};
	int n = sizeof(A) / sizeof(int);

    cout << validSubarrays(A, n);

	return 0;
}