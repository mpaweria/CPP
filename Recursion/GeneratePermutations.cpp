#include<iostream>
using namespace std;

void generatePermutations(char inp[], int n, int i) {
    // base case
    if(i == n) {
        cout << inp << endl;
        return;
    }

    // recursive case
    for(int j=i; j<n; j++) {
        swap(inp[i], inp[j]);
        generatePermutations(inp, n, i+1);
        swap(inp[i], inp[j]);   // backtracking
    }
}

int main() {
    char inp[] = "abc";

    generatePermutations(inp, 3, 0);

    return 0;
}