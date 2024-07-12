#include<iostream>
using namespace std;

int main() {
    int n = 2, k = 3;
    int mask = 1 << k;
    int ans = n | mask;
    cout << "After setting " << k << "th bit, the new value of " << n << " is " << ans;

    return 0;
}