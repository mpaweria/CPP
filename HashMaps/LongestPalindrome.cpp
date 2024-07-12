#include<iostream>
#include<unordered_set>
using namespace std;

int longestPalindrome(string str) {
    unordered_set<char> set;
    int longestLength = 0;

    for(char c: str){
        if(set.find(c) != set.end()){
            longestLength += 2;
            set.erase(c);
        } else {
            set.insert(c);
        }
    }

    if(set.size())
        longestLength++;

    return longestLength;
}

int main() {

    string str = "aabccccddef";

    cout << longestPalindrome(str);

}