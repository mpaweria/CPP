#include<iostream>
using namespace std;

int fact(int n) {
    // base case
    if (n == 1 || n == 0)
        return 1;

    // recursive case
    return n * fact(n-1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << fact(n);

    return 0;
}