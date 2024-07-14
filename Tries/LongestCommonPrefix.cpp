#include<iostream>
#include<unordered_map>
using namespace std;

class node {
    public:
        char ch;
        bool isTerminal;
        int frequency;
        unordered_map<char, node*> childMap;

        node(char ch) {
            this->ch = ch;
            this->isTerminal = false;
            this->frequency = 0;
        }
};

class trie {
    node* root;
    int n;

    public:
        trie() {
            root = new node('#');
            n = 0;
        }

        void insert(string str) {
            node* curr = root;

            for(char ch: str) {
                if(curr->childMap.find(ch) == curr->childMap.end()){
                    node* n = new node(ch);
                    curr->childMap[ch] = n;
                }
                curr = curr->childMap[ch];
                curr->frequency++;
            }
            curr->isTerminal = true;
            n++;
        }

        string longestCommonPrefix(string str) {
            node* curr = root;
            string prefix = "";

            for(char ch: str) {
                curr = curr->childMap[ch];
                if(curr->frequency == n)
                    prefix += ch;
                else
                    break;
            }
            return prefix;
        }
};

int main() {

	string words[] = {"flys", "fly", "flow", "floor"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	cout << t.longestCommonPrefix(words[0]) << endl;

	return 0;
}