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

int helperUsingTrie(int arr[], int n) {
    int cXOR[n+1] = {0};

    for(int i=1; i<=n; i++)
        cXOR[i] = cXOR[i-1] ^ arr[i-1];

    trie t;
    for(int i=0; i<n; i++)
        t.insert(cXOR[i]);

    return t.maximumXOR(cXOR, n+1); 
}

int main() {

	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr) / sizeof(int);

	cout << helperUsingTrie(arr, n) << endl;


	return 0;
}