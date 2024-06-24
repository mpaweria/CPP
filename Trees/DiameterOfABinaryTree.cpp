/*

given the pre-order traversal of a binary tree, design a recursive algorithm
to compute its diameter

	  diameter of a binary tree is the length of the longest path between any
	  two TreeNodes in the binary tree.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 5

          Input  : 10 20 30 50 70 -1 -1 -1 -1 40 -1 60 -1 80 -1 -1 90 -1 -1
          Output : 6

          Input  : 10 20 -1 -1 30 40 60 80 -1 -1 -1 -1 50 -1 70 -1 90 -1 -1
          Output : 6

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
		this->left = this->right = NULL;
	}
};

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

// Time O(n^2)
int computeDiameter(TreeNode* root) {
    // base case
    if(!root)
        return 0;

    // recursive case
    int leftDiameter = computeDiameter(root->left);
    int rightDiameter = computeDiameter(root->right);
    int rootDiameter = treeHeight(root->left) + treeHeight(root->right) + 2;

    return max(leftDiameter, max(rightDiameter, rootDiameter));
}

pair<int, int> computeDiameterEfficient(TreeNode* root) {
    // base case
    if(!root)
        return {0, -1};

    // recursive case
    pair<int, int> left= computeDiameterEfficient(root->left);
    pair<int, int> right = computeDiameterEfficient(root->right);

    int rootDiameter = left.second + right.second  + 2;

    int diameter = max(left.first, max(right.first, rootDiameter));

    return {diameter, 1 + max(left.second, right.second)};
}

int main() {

	TreeNode* root = buildTree();

	cout << computeDiameter(root) << endl;

	pair<int, int> p = computeDiameterEfficient(root);

	cout << p.first << endl;

	return 0;
}