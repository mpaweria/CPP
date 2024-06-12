#include<iostream>
using namespace std;

void countMoves(int n, char s, char d, char h) {
    // base case
    if(n == 0)
        return;

    // recursive case
    countMoves(n-1, s, h, d);
    cout << "Move disk from " << s << " to " << d << endl;
    countMoves(n-1, h, d, s);
}

int main() {
    int n = 3;

    countMoves(n, 'A', 'C', 'B');

    return 0;
}