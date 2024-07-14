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

    public:
        trie() {
            root = new node('#');
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
        }

        string uniquePrefix(string str) {
            node* curr = root;

            string ans = "";
            for(char ch: str) {
                curr = curr->childMap[ch];
                ans += ch;
                if(curr->frequency == 1) {
                    return ans;
                }
            }
            return "";
        }
};

int main() {

	string words[] = {"code", "coder", "coding", "new", "neon"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	for (string word : words) {
		cout << "uniquePrefix(" << word << ") =" << t.uniquePrefix(word) << endl;
	}

	return 0;
}