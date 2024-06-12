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

        bool flag = true;

        for(int k = j+1; k<n; k++) {
            if(inp[j] == inp[k]) {
                flag = false;
                break;
            }
        }

        if(flag) {
            swap(inp[i], inp[j]);
            generatePermutations(inp, n, i+1);
            swap(inp[i], inp[j]);   // backtracking
        }
    }
}

int main() {
    char inp[] = "aabc";

    generatePermutations(inp, 4, 0);

    return 0;
}