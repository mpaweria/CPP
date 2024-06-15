#include<iostream>
#include<stack>
#include<vector>

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

int main() {

	int A[] = {0, 3, 5, 4, 1, 6, 2};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = nearestSmallerLeft(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	return 0;
}