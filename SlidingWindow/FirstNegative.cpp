#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	vector<int> arr = { -2, 0, -1, 2, -3, 1, 3};
	int n = arr.size();
	int k = 4;

    int i = 0, j = 0;

    queue<int> q;

    while (j < k)
    {
        if(arr[j] < 0)
            q.push(arr[j]);
        
        j++;
    }
    
    vector<int> v;

    while (j < n)
    {
        !q.empty() ? v.push_back(q.front()) : v.push_back(0);

        if(arr[i] < 0)
            q.pop();
        i++;

        if(arr[j] < 0)
            q.push(arr[j]);
        j++;
    }

    !q.empty() ? v.push_back(q.front()) : v.push_back(0);

    for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

    return 0;
}