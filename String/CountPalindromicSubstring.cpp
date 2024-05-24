#include<iostream>
using namespace std;

bool isPalindrome(string str) {
    int i = 0, j = str.length() - 1;

    while(i <= j) {
        if(str[i++] != str[j--])
        {
            return false;
        }
    }
    return true;
}

// Time O(n^3)
int countPalindromicSubstr(const string& str, int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            string subStr = str.substr(i, j-i+1);
            if(isPalindrome(subStr))
                count++;
        }
    }
    return count;
}

int countPalindromicSubstrOptimized(const string& str, int n) {
    int count = 0;
    // count odd length palindromes
    for(int i=0; i<n; i++){
        int j = 0;
        while(i + j < n && i - j >= 0 && str[i+j] == str[i-j]) {
            count++;
            j++;
        }
    }
    // count odd length palindromes
    for(double i=0.5; i<n; i++){
        double j = 0.5;
        while(i + j < n && i - j >= 0 && str[static_cast<int>(i+j)] == str[static_cast<int>(i-j)]) {
            count++;
            j++;
        }
    }
    return count;
}

int main() {
    string str = "abaaba";

    cout << countPalindromicSubstrOptimized(str, str.length());

    return 0;
}