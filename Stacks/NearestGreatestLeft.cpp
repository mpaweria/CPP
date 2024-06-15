#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nearestGreaterLeft(int A[], int n) {
    stack<int> s;
    vector<int> vec;

    for(int i=0; i<n; i++) {
        while (!s.empty() && s.top() <= A[i])
        {
            s.pop();
        }
        if(s.empty())
            vec.push_back(-1);
        else
            vec.push_back(s.top());
        
        s.push(A[i]);
    }
    return vec;
}

int main() {

	int A[] = {5, 2, 0, 4, 1, 3, 6};
	int n = sizeof(A) / sizeof(int);

	vector<int> v = nearestGreaterLeft(A, n);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	return 0;
}