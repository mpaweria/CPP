#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    vector<int> ropeLengths = {4, 3, 2, 6};

    priority_queue<int, vector<int>, greater<int>> q; 

    for(int r: ropeLengths)
        q.push(r);

    int sum = 0;

    while (q.size() > 1)
    {
        int first = q.top();
        q.pop();

        int second = q.top();
        q.pop();

        sum += first + second;
        q.push(first + second);
    }
    cout << sum;

    return 0;
}