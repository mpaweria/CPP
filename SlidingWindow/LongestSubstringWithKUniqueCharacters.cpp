#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

    int i = 0, j = 0, maxLength = 0, uniqueCharacters = 0;
    unordered_map<char, int> map;

    while (j < n)
    {
        if(map.find(s[j]) == map.end())
            uniqueCharacters++;

        map[s[j]]++;

        while(uniqueCharacters > k) {
            map[s[i]]--;

            if(map[s[i]] == 0)
                uniqueCharacters--;

            i++;
        }

        if(uniqueCharacters == k) {
            maxLength = max(maxLength, j-i+1);
        }

        j++;
    }
    
    cout << maxLength;

    return 0;
}