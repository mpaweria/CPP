#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int> v) {
    int slow = v[0], fast = v[0];

    while(true) {
        slow = v[slow];
        fast = v[v[fast]];

        if(slow == fast)
            break;
    }

    slow = v[0];

    while (slow != fast)
    {
        slow = v[slow];
        fast = v[fast];
    }
    return slow;
}

int main() {
    vector<int> v = {1, 3, 4, 2, 3};

    cout << findDuplicate(v);

    return 0;
}