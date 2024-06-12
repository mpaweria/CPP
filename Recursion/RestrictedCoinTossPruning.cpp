#include<iostream>
using namespace std;

void coinToss(int n, int i, char s[]) {
    // base case
    if(i==n) {
        s[i] = '\0';
        cout << s << endl;
        return;
    }

    // recursive case
    if(i == 0 || s[i-1] != 'H') {
        s[i] = 'H';
        coinToss(n, i+1, s);
    }

    s[i] = 'T';
    coinToss(n, i+1, s);
}

int main() {
    int n = 4;
    char s[n];

    coinToss(n, 0, s);

    return 0;
}