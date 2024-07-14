#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    string s = "pwwkew";
    int i = 0, j = 0, maxLength = 0;
    unordered_map<char, int> map;

    while(j < s.size()) {
        map[s[j]]++;

        while(map[s[j]] > 1) {
            map[s[i]]--;
            i++;
        }

        maxLength = max(maxLength, j-i+1);

        j++;
    }

    cout << maxLength;

    return 0;
}