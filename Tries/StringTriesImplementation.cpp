#include<iostream>
#include<unordered_map>
using namespace std;

class node {
    public:
        char ch;
        bool isTerminal;
        unordered_map<char, node*> childMap;

        node(char ch) {
            this->ch = ch;
            this->isTerminal = false;
        }
};

class trie {
    node* root;

    public:
        trie() {
            root = new node('#');
        }

        // time : O(len(str))
        void insert(string str) {
            node* curr = root;

            for(char c: str) {
                if(curr->childMap.find(c) == curr->childMap.end()) {
                    node* temp = new node(c);
                    curr->childMap[c] = temp;
                }
                curr = curr->childMap[c];
            }
            curr->isTerminal = true;
        }

        bool search(string str) {
            node* curr = root;
            
            for(char ch: str) {
                if(curr->childMap.find(ch) == curr->childMap.end()) {
                    return false;
                }
                curr = curr->childMap[ch];
            }
            return curr->isTerminal;
        }
};

int main() {

	string words[] = {"code", "coder", "coding", "block", "blocks", "news"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	string queries[] = {"code", "coding", "blocked", "block", "news", "new"};

	for (string query : queries) {
		t.search(query) ? cout << query << " is present" << endl :
		                       cout << query << " is absent" << endl;
	}

	cout << endl;

	return 0;
}