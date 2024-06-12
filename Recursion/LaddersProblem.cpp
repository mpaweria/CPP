#include<iostream>
using namespace std;

int count = 0;

int numberOfWays(int n, int k, int i) {
    // base case
    if(i == n){
        return 1;
    }

    // recursive case
    int count = 0;
    for(int j=1; j<=k; j++) {
        if(i + j <= n) {
            count += numberOfWays(n, k, i+j);
        }
    }
    return count;
}

int main() {
    int n = 4, k = 3;
    
    cout << numberOfWays(n, k, 0);

    return 0;
}