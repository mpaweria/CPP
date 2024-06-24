/*
Design a recursive algorithm to build a binary tree given its pre-order traversal.
eg: preOrder : 5 4 11 7 -1 -1 2 -1 -1 8 13 -1 -1 4 -1 -1 -1  1 -1 -1
*/

#include<iostream>
using namespace std;

class TreeNode {
    public:     
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

void printPreOrder(TreeNode* root) {
    // base case
    if(root == NULL)
        return;

    // recursive case
    cout << root->val << "  ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

TreeNode* buildTree() {
    int data;
    cin >> data;

    // base case
    if(data == -1)
        return NULL;

    // recursive 
    TreeNode* root = new TreeNode(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

bool pathExists(TreeNode* root, int target) {
    // base case
    if(!root)
        return false;

    if(!root->left && !root->right) {
        if(root->val == target)
            return true;

        return false;
    }

    // recrusive case
    return pathExists(root->left, target-root->val) || pathExists(root->right, target-root->val);
}

int main() {

	TreeNode* root = NULL;

    cout << "Enter pre-order of tree: ";
	root = buildTree();

	printPreOrder(root);

    int target = 22;
	cout << endl << "Path exists: ";

    pathExists(root, target) ? cout << "true" : cout << "false";

	return 0;
}