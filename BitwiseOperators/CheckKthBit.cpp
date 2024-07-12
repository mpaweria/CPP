#include<iostream>
using namespace std;

int main() {
    int n = 42, k = 4;
    int mask = 1 << k;
    int ans = n & mask;

    if(ans) {
        cout << k << "th bit of " << n << " is set";
    } else {
        cout << k << "th bit of " << n << " is not set";
    }

    return 0;
}