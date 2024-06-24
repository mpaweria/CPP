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

int numberOfPaths(TreeNode* root, int target) {
    // base case
    if(!root)
        return 0;

    // recursive case
    int count = 0;

    if(root->val == target)
        count++;

    return count + numberOfPaths(root->left, target-root->val) + numberOfPaths(root->right, target-root->val);
}

int pathSum(TreeNode* root, int target) {
    // base case
    if(!root)
        return 0;

    // recursive case

    return numberOfPaths(root, target) + pathSum(root->left, target) + pathSum(root->right, target);
}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 8;

	cout << pathSum(root, targetSum) << endl;

	return 0;
}