#include<iostream>
using namespace std;

class node {
    public:
        node* left;
        node* right;

        node() {
            this->left = NULL;
            this->right = NULL;
        }
};

class trie {
    node* root;

    public:
        trie() {
            root = new node();
        }

        void insert(int num) {
            node* curr = root;

            for(int i=31; i>=0; i--){
                int ithBit = (num >> i) & 1;

                if(ithBit) {
                    if(!curr->right)
                        curr->right = new node();
                    curr = curr->right;
                } else {
                    if(!curr->left)
                        curr->left = new node();
                    curr = curr->left;
                }
            }
        }

        bool search(int num) {
            node* curr = root;

            for(int i=31; i>=0; i--) {
                int ithBit = (num >> i) & 1;

                if(ithBit) {
                    if(!curr->right)
                        return false;
                    curr = curr->right;
                } else {
                    if(!curr->left)
                        return false;
                    curr = curr->left;
                }
            }
            return true;
        }
};

int main() {

	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr) / sizeof(int);

	trie t;
	for (int i = 0; i < n; i++) {
		t.insert(arr[i]);
	}

	int brr[] = {1, 2, 5, 10, 25, 0};
	int m = sizeof(brr) / sizeof(int);

	for (int i = 0; i < m; i++) {
		t.search(brr[i]) ? cout << brr[i] << " is present" << endl :
		                        cout << brr[i] << " is absent" << endl;
	}

	cout << endl;

	return 0;
}