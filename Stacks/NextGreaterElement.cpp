#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nearestGreaterRight(int A[], int n) {
    stack<int> s;
    vector<int> vec;
    for(int i=n-1; i>=0; i--) {

        while(!s.empty() && A[i] >= s.top())
            s.pop();

        if(s.empty())
            vec.push_back(-1);
        else {
            vec.push_back(s.top());
        }
        s.push(A[i]);
    }
    reverse(vec.begin(), vec.end());

    return vec;
}

int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = nearestGreaterRight(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}