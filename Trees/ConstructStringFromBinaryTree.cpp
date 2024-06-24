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

string stringFromBinaryTree(TreeNode* root) {
    // base case
    if(!root)
        return "";

    // recursive case
    if(root->left != NULL && root->right != NULL) {
        return to_string(root->val) + "(" + stringFromBinaryTree(root->left) + ")(" + stringFromBinaryTree(root->right) + ")";
    } else if(root->left != NULL) {
        return to_string(root->val) + "(" + stringFromBinaryTree(root->left) + ")";
    } else if(root->right != NULL) {
        return to_string(root->val) +"()(" + stringFromBinaryTree(root->right) + ")";
    }
    return to_string(root->val);
}

int main() {

	TreeNode* root = NULL;

    cout << "Enter pre-order of tree: ";
	root = buildTree();

	printPreOrder(root);

	cout << endl;

    cout << stringFromBinaryTree(root);

	return 0;
}