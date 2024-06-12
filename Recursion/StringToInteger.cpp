#include<iostream>
using namespace std;

int strToInt(string str, int num, int i, int n) {
    // base case
    if(i == n-1)
        return num + str[i] - '0';

    // recursive case
    num += str[i] - '0';
    num = strToInt(str, num*10, i+1, n);
    return num;
}

int stringToInt(string str, int n) {
    // base case
    if(n == 0)
        return 0;

    // recursive case
    string subString = str.substr(0, n-1);
    int num = stringToInt(subString, n-1);

    return (num * 10) + (str[n-1] - '0');
}

int main() {
    string str = "12345";

    cout << strToInt(str, 0, 0, str.length()) << endl;
    cout << stringToInt(str, str.length());

    return 0;
}