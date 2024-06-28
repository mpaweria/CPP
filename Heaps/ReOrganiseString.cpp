#include<iostream>
#include<queue>
using namespace std;

string reorganise(string str) {
    int freq[26] = {0};

    for(char ch: str)
        freq[ch-'a']++;

    priority_queue<pair<int, char>> maxHeap;

    for(int i=0; i<26; i++) {
        if(freq[i] > 0) {
            maxHeap.push({freq[i], i+'a'});
        }
    }

    string out = "";

    while (!maxHeap.empty())
    {
        if(maxHeap.size() == 1) {
            pair<int, char> firstPair = maxHeap.top();
            maxHeap.pop();

            if(firstPair.first > 1)
                out = "";
            else
                out += firstPair.second;
        } else {
            pair<int, char> firstPair = maxHeap.top();
            maxHeap.pop();

            pair<int, char> secondPair = maxHeap.top();
            maxHeap.pop();

            out += firstPair.second;
            firstPair.first--;

            out += secondPair.second;
            secondPair.first--;

            if(firstPair.first > 0)
                maxHeap.push(firstPair);
            if(secondPair.first > 0)
                maxHeap.push(secondPair);
        }
    }
    return out;
}

int main() {

    string str = "aaaaabbc";

    cout << reorganise(str) << endl;

    return 0;
}