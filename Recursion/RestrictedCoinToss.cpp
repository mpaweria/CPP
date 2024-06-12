#include<iostream>
using namespace std;

void coinToss(int n, int i, char s[]) {
    // base case
    if(i==n) {
        s[i] = '\0';
        for(int j=0; j<n-1; j++) {
            if(s[j] == 'H' && s[j+1] == 'H')
                return;
        }
        cout << s << endl;
        return;
    }

    // recursive case
    s[i] = 'H';
    coinToss(n, i+1, s);

    s[i] = 'T';
    coinToss(n, i+1, s);
}

int main() {
    int n = 4;
    char s[n];

    coinToss(n, 0, s);

    return 0;
}