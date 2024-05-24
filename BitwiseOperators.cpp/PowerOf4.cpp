#include<iostream>
using namespace std;

int main() {
    int n = 32;
    if(((n & n-1) == 0) && ((n & 0xaaaa) == 0))
        cout << n << " is a power of 4";
    else
        cout << n << " is not a power of 4";

    return 0;
}