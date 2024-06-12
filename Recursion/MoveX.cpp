#include<iostream>
using namespace std;

string moveX(string str, int i, int n) {
    // base case
    if(i == n)
        return "";

    // recursive case
    if(str[i] == 'x')
        return moveX(str, i+1, n) + str[i];
    
    return str[i] + moveX(str, i+1, n);
}

int main() {
    string str = "xxbxcxa";

    cout << moveX(str, 0, str.length());

    return 0;
}