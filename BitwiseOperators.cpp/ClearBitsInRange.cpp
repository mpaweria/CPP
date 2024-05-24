#include<iostream>
using namespace std;

int main() {
    int n = 169, i = 2, j = 5;
    int mask1 = -1 << (j+1), mask2 = (1 << i)-1;
    int mask = mask1 | mask2;

    cout << (n & mask);

    return 0;
}