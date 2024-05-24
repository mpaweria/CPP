#include<iostream>
using namespace std;

void isPalindrome(string str) {
    int i = 0, j = str.length() - 1;

    while(i <= j) {
        if(str[i++] != str[j--])
        {
            cout << "Not Palindrome";
            return;
        }
    }
    cout << "Palindrome";
}

int main() {
    string str = "abccba";

    isPalindrome(str);

    return 0;
}