/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

*/

#include<iostream>
#include<cmath>
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

int treeHeight(TreeNode* root) {
    // base case
    if(!root)
        return -1;

    // recursive case
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

// Time - O(n^2)
bool isTreeHeightBalanced(TreeNode* root) {
    // base case
    if(!root)
        return true;

    // recursive case
    return abs(treeHeight(root->left) - treeHeight(root->right)) <= 1 && isTreeHeightBalanced(root->left) && isTreeHeightBalanced(root->right); 
}

pair<bool, int> isTreeHeightBalancedOptimized(TreeNode* root) {
    // base case
    if(!root) {
        return {true, -1};
    }

    // recursive case
    pair<bool, int> left = isTreeHeightBalancedOptimized(root->left);
    pair<bool, int> right = isTreeHeightBalancedOptimized(root->right);

    bool isBalanced = abs(left.second - right.second) <= 1 && left.first && right.first;
    
    return {isBalanced, 1 + max(left.second, right.second)};
}

int main() {

	TreeNode* root = NULL;

    cout << "Enter pre-order of tree: ";
	root = buildTree();

	printPreOrder(root);

	cout << endl << "Is tree height balanced: ";

    pair<bool, int> ans = isTreeHeightBalancedOptimized(root);

    ans.first ? cout << "true" : cout << "false";

	return 0;
}