#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    vector<int> v = {60, 50, 10, 20, 30, 40};
    int k = 3;

    priority_queue<int> maxHeap(v.begin(), v.end());

    while (k--)
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    return 0;
}