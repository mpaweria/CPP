#include<iostream>
using namespace std;

// Print from 1 to n
void printIncreasing(int n) {
    // base case
    if(n == 0)
        return;

    // recursive case
    printIncreasing(n-1);
    cout << n << " ";
}

int main() {
    int n = 8;

    printIncreasing(n);

    return 0;
}