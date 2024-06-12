#include<iostream>
using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dialKeyPad(char inp[], char out[], int i, int j) {
    // base case
    if(inp[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case
    int di = inp[i] - '0';
    if(di == 0 || di == 1) {
        dialKeyPad(inp, out, i+1, j);
        return;
    }

    string options = keypad[di];

    for(char option: options) {
        out[j] = option;
        dialKeyPad(inp, out, i+1, j+1);
    }
}

int main() {

    char inp[] = "73";
    char out[10];

    dialKeyPad(inp, out, 0, 0);
    return 0;
}