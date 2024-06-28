#include<iostream>
#include<queue>
using namespace std;

#define mh priority_queue<int, vector<int>, greater<int>>

void print(mh minHeap) { // minHeap is passed by value
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {
    mh minHeap;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Enter stream: ";
    int val;
    for(int i=0; i<k; i++) {
        cin >> val;
        minHeap.push(val);
    }

    while(true) {
        cin >> val;
        if(val == -1)
            print(minHeap);
        else {
            if(val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
            }
        }
    }

    return 0;
}