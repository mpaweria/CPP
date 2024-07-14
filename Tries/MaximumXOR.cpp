#include<iostream>
#include<climits>

using namespace std;

class node {
public:

	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

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

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (1 << i)&n;
			if (!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if (!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if (!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

    int helper(int n) {
        node* curr = root;
        int ans = 0;

        for(int i=31; i>=0; i--){
            int ithBit = (n >> i) & 1;

            if(ithBit) {
                if(curr->left) {
                    ans += 1 << i;
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            } else {
                if(curr->right) {
                    ans += 1 << i;
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            }
        }
        cout << n << " ^ " << (n ^ ans) << " = " << ans << endl;
        return ans;
    }

    int maximumXOR(int x[], int n) {
        int maxXOR = 0;
        for(int i=0; i<n; i++){
            maxXOR = max(maxXOR, helper(x[i]));
        }
        return maxXOR;
    }
};

int main() {

	int x[] = {2, 4, 5, 8, 10};
	int n = sizeof(x) / sizeof(int);

	trie t;

	for (int i = 0; i < n; i++) {
		t.insert(x[i]);
	}

	cout << t.maximumXOR(x, n) << endl;

	return 0;
}