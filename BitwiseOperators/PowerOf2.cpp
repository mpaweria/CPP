#include<iostream>
using namespace std;

int main() {
    int n = 16;

    if((n & n-1) == 0)
        cout << n << " is a power of 2.";
    else 
        cout << n << " is not a power of 2.";

    return 0;
}