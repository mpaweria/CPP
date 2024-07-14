#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    string str1 = "cbaebabacb", str2 = "abc";

    unordered_map<char, int> str2Map;

    for(char c: str2) {
        str2Map[c]++;
    }

    int i = 0, j = 0, k = str2.size();
    unordered_map<char, int> str1Map;

    while (j < k)
    {
        str1Map[str1[j]]++;
        j++;
    }
    
    int count = 0;
    while (j < str1.length())
    {
        if(str1Map == str2Map) {
            count ++;
        }

        str1Map[str1[i]]--;

        if(str1Map[str1[i]] == 0)
            str1Map.erase(str1[i]);
            
        i++;
        str1Map[str1[j]]++;
        j++;
    }
    if(str1Map == str2Map) {
        count ++;
    }
    cout << count;

    return 0;
}