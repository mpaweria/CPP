#include<iostream>
using namespace std;

int mul(int n1, int n2) {
    // base case
    if(n2 == 0)
        return 0;

    // recursive case
    return n1 + mul(n1, n2-1);
}

int main() {
    int n1 = 3, n2 = 9;
    if(n2 > n1)
        swap(n1, n2);
    cout << mul(n1, n2);

    return 0;
}