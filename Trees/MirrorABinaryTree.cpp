/*
Design a recursive algorithm to build a binary tree given its pre-order traversal.
eg: preOrder : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
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

void mirrorTree(TreeNode* root) {
    // base case
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
        return;

    // recursive case
    mirrorTree(root->right);
    mirrorTree(root->left);

    swap(root->left, root->right);
}

int main() {

	TreeNode* root = NULL;

    cout << "Enter pre-order of tree: ";
	root = buildTree();

	printPreOrder(root);

	cout << endl;

    mirrorTree(root);

    printPreOrder(root);

	cout << endl;

	return 0;
}