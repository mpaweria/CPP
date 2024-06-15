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

int main() {

	int A[] = {2, 5, 1, 3, 6, 4, 0};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = nearestSmallerRight(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	return 0;
}