#include<iostream>
using namespace std;

void generateSubsequences(char inp[], char out[], int i, int j) {
    // base case
    if(inp[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case
    out[j] = inp[i];
    generateSubsequences(inp, out, i+1, j+1);

    generateSubsequences(inp, out, i+1, j);
}

int main() {
    char inp[] = "abcd";
    char out[10];

    generateSubsequences(inp, out, 0, 0);

    return 0;
}