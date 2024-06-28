#include<iostream>
#include<queue>

using namespace std;

int main() {
    int data;
    cin >> data;

    double median = data;
    cout << median << " ";

    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    leftMaxHeap.push(data);

    while (data != -1)
    {
        cin >> data;

        if(data < median) {
            if(leftMaxHeap.size() < rightMinHeap.size()) {
                leftMaxHeap.push(data);
                median = (leftMaxHeap.top() + rightMinHeap.top())/2.0;
            }
            else if(leftMaxHeap.size() == rightMinHeap.size()) {
                leftMaxHeap.push(data);
                median = leftMaxHeap.top();
            }
            else {
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();

                leftMaxHeap.push(data);
                median = (leftMaxHeap.top() + rightMinHeap.top())/2.0;
            }
        } else {
            if(leftMaxHeap.size() > rightMinHeap.size()) {
                rightMinHeap.push(data);
                median = (leftMaxHeap.top() + rightMinHeap.top())/2.0;
            }
            else if(leftMaxHeap.size() == rightMinHeap.size()) {
                rightMinHeap.push(data);
                median = rightMinHeap.top();
            }
            else {
                leftMaxHeap.push(rightMinHeap.top());
                rightMinHeap.pop();

                rightMinHeap.push(data);
                median = (leftMaxHeap.top() + rightMinHeap.top())/2.0;
            }            
        }
        cout << median << " ";
    }
    
}