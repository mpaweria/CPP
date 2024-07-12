#include<iostream>
using namespace std;

int main() {
    int a = 2, n = 3, ans = 1;
    int weight = a, num = n;

    while(n) {
        if(n & 1){
            ans *= weight;
        }
        weight *= weight;
        n = n >> 1;
    }

    cout << a << " raised to the power " << num << " is " << ans;

    return 0;
}