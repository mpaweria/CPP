#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> tFreqMap;

    for(char c: t) {
        tFreqMap[c]++;
    }

    int tCount = tFreqMap.size();

    int i = 0, j = 0, minLength = INT_MAX, sIndex = 0;

    while(j < s.length()) {
        char ch = s[j];
        
        if(tFreqMap.find(ch) != tFreqMap.end()) {
            tFreqMap[ch]--;
            if(tFreqMap[ch] == 0)
                tCount--;
        }

        if(tCount == 0) {
            if(j-i+1 < minLength) {
                minLength = j-i+1;
                sIndex = i;
            }

            while (tCount == 0)
            {
                char out = s[i];
                if(tFreqMap.find(out) != tFreqMap.end()) {
                    tFreqMap[out]++;
                    if(tFreqMap[out] == 1) {
                        tCount++;
                        i++;
                    } else{
                        i++;
                        if(j-i+1 < minLength) {
                            minLength = j-i+1;
                            sIndex = i;
                        }
                    }
                } else {
                    i++;
                    if(j-i+1 < minLength) {
                        minLength = j-i+1;
                        sIndex = i;
                    }
                }
            }            
        }
        j++;
    }
    return minLength == INT_MAX ? "" : s.substr(sIndex, minLength);
}

int main() {

	string s = "adobecodebanc";
	string t = "abc";

	cout << minWindow(s, t) << endl;

	return 0;
}