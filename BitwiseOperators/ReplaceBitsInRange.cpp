#include<iostream>
using namespace std;

int main() {
    int n = 169, m = 10, i = 3, j = 6;
    int mask1 = (-1 << (j+1)) | ((1 << i)-1), mask2 = m << i;
    
    cout << ((n & mask1) | mask2);

    return 0;
}