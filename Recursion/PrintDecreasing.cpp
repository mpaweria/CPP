#include<iostream>
using namespace std;

void printDecreasing(int n) {
    // base case
    if(n == 0)
        return;

    // recursive case
    cout << n << " ";
    printDecreasing(n-1);
}

int main() {
    int n = 5;

    printDecreasing(n);

    return 0;
}