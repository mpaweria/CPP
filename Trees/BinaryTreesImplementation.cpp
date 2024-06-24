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

void printInOrder(TreeNode* root) {
    // base case
    if(root == NULL)
        return;

    // recursive case
    printInOrder(root->left);
    cout << root->val << "  ";
    printInOrder(root->right);
}

void printPostOrder(TreeNode* root) {
    // base case
    if(root == NULL)
        return;

    // recursive case
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->val << "  ";
}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(10);
	root->left = new TreeNode(20);
	root->right = new TreeNode(30);
	root->left->left = new TreeNode(40);
	root->left->right = new TreeNode(50);
	root->right->right = new TreeNode(60);
	root->left->right->left = new TreeNode(70);

	printPreOrder(root);

	cout << endl;

	printInOrder(root);

	cout << endl;

	printPostOrder(root);

	cout << endl;

	return 0;
}