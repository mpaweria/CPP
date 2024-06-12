#include<iostream>
using namespace std;

void replacePi(char inp[], int i) {
    // base case
    if(inp[i] == '\0')
        return;

    // recursive case
    if(inp[i] == 'p' && inp[i+1] == 'i') {

        int j = i+2;
        while(inp[j] != '\0')
            j++;

        while(j >= i+2) {
            inp[j+2] = inp[j];
            j--;
        }

        inp[i] = '3';
        inp[i+1] = '.';
        inp[i+2] = '1';
        inp[i+3] = '4';

        replacePi(inp, i+4);
    }
    else 
        replacePi(inp, i+1);
}

int main() {
    char inp[20] = "pippii";

    replacePi(inp, 0);

    cout << inp;

    return 0;
}