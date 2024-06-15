#include<iostream>
#include<stack>
#include <vector>

using namespace std;

vector<int> stockSpan(int A[], int n) {
    stack<pair<int, int>> s;
    vector<int> vec;

    for(int i=0; i<n; i++) {
        while (!s.empty() && s.top().first <= A[i])
        {
            s.pop();
        }
        if(s.empty())
            vec.push_back(i - -1);
        else
            vec.push_back(i - s.top().second);
        
        s.push({A[i], i});
    }
    return vec;
}

vector<int> stockSpan2(int A[], int n) {
    stack<int> s;
    vector<int> vec;

    for(int i=0; i<n; i++) {
        while (!s.empty() && A[s.top()] <= A[i])
        {
            s.pop();
        }
        if(s.empty())
            vec.push_back(i - -1);
        else 
            vec.push_back(i - s.top());
        s.push(i);
    }
    return vec;
}

int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 85, 500};
	int n = sizeof(A) / sizeof(int);

	vector<int> span = stockSpan2(A, n);

	for (int i = 0; i < span.size(); i++) {
		cout << span[i] << " ";
	}

	cout << endl;

	return 0;
}