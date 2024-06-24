#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

int numMoves = 0;

int distributeCoins(TreeNode* root) {
    // base case
    if(!root)
        return 0;

    // recursive case
    int leftReq = distributeCoins(root->left);
    int rightReq = distributeCoins(root->right);

    int rootReq = (leftReq + rightReq + 1) - root->val;

    numMoves += abs(leftReq) + abs(rightReq);

    return rootReq;
}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(3);

	root->left = new TreeNode(0);
	root->right = new TreeNode(0);

	distributeCoins(root);

	cout << numMoves << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(3);
	// root->right = new TreeNode(0);

	// distributeCoins(root);

	// cout << numMoves << endl;

	return 0;
}