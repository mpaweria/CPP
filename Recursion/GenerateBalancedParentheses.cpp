#include<iostream>
using namespace std;

void generateParentheses(int i, int open, int close, int n, char out[]) {
    // base case
    if(i == 2*n) {
        out[i] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case
    if(open < n) {
        out[i] = '(';
        generateParentheses(i+1, open+1, close, n, out);
    }
    if(close < open) {
        out[i] = ')';
        generateParentheses(i+1, open, close+1, n, out);
    }
}

int main() {
    int n = 2;
    char out[2*n];

    generateParentheses(0, 0 ,0, n, out);

    return 0;
}