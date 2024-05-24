#include<iostream>
using namespace std;

// bool isGoodString(const string &str) {
//     for(int i=0; i<str.length(); i++) {
//         char ch = str[i];
//         if(!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
//             return false;
//         }
//     }
//     return true;
// }

// Time: O(n^3)
// int lengthOfLongestGoodSubstring(const string &str, int n) {
//     int largestLength = 0;
//     for(int i=0; i<n; i++) {
//         for(int j=i; j<n; j++) {
//             string subStr = str.substr(i,j-i+1);
//             if(isGoodString(subStr)) {
//                 largestLength = max(largestLength, (int)subStr.length());
//             }
//         }
//     }
//     return largestLength;
// }

// Time: O(n)
int lengthOfLongestGoodSubstring(const string &str, int n) {
    int maxSoFar = 0, length = 0;

    for(int i=0; i<n; i++) {
        char ch = str[i];
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            length++;
            maxSoFar = max(maxSoFar, length);
        } else {
            length = 0;
        }
    }
    return maxSoFar;
}

int main() {
    string str = "cbcdppieloiuoi";

    cout << lengthOfLongestGoodSubstring(str, str.length());

    return 0;
}