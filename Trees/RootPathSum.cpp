/*
eg: preOrder : 2 7 3 1 -1 -1 8 -1 -1 3 -1 -1 6 4 -1 -1 5 -1 -1
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

int main() {

	TreeNode* root = NULL;

    cout << "Enter pre-order of tree: ";
	root = buildTree();

	printPreOrder(root);

	cout << endl;

    int target = 12;
    cout << "Number of paths: " << numberOfPaths(root, target);

	return 0;
}