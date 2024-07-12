#include<iostream>
using namespace std;

int main() {
    int n = 304, count = 0, maxCount = 0;
    int num = n;
    while(n) {
        if(n & 1) {
            count++;
            maxCount = max(maxCount, count);
        } else
            count = 0;
        n = n >> 1;
    }
    cout << "The length of longest consecutive sequence of ones in " << num << " is " << maxCount;

    return 0;
}