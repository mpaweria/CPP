#include<iostream>
using namespace std;

int main() {
    int n = 42, k = 3;
    int mask = ~(1 << k);
    int ans = n & mask;
    cout << "After clearing " << k << "th bit, the new value of " << n << " is " << ans;

    return 0;
}