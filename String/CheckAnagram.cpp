#include<iostream>
#include<vector>
using namespace std;

void checkAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        cout << "Not Anagram";
        return;
    }

    vector<int> freq(26, 0);

    for(int i = 0; i < str1.length(); i++) {
        freq[str1[i]-'a']++;
    }

    for(int i = 0; i < str2.length(); i++) {
        if(freq[str2[i]- 'a'] == 0)
        {
            cout << "Not Anagram";
            return;
        }
        freq[str2[i]-'a']--;
    }
    cout << "Anagram";
}

int main() {
    string str1 = "abacbac", str2 = "aabbbcc";

    checkAnagram(str1, str2);

    return 0;
}