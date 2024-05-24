#include<iostream>
using namespace std;

int main() {
    int n = 169, k = 4;
    int mask = -1 << k;

    cout << (n & mask);

    return 0;
}