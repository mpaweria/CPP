/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

int findMinimumIterative(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MAX;
	}

	TreeNode* temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}

	return temp->val;

}

int findMaximumIterative(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MIN;
	}

	TreeNode* temp = root;
	while (temp->right != NULL) {
		temp = temp->right;
	}

	return temp->val;

}

bool isBST(TreeNode* root) {
    // base case
    if(!root)
        return true;

    // recursive case
    bool isLeftBST = isBST(root->left);

    bool isRightBST = isBST(root->right);

    bool isRootBST = root->val > findMaximumIterative(root->left) && root->val < findMinimumIterative(root->right);

    return isLeftBST && isRightBST && isRootBST;
}

class Triple {
    public:
        bool isBST;
        int minValue;
        int maxValue;
};

Triple isBSTEfficient(TreeNode* root) {
    Triple t;

    // base case
    if(!root) {
        t.isBST = true;
        t.maxValue = INT_MIN;
        t.minValue = INT_MAX;
        return t;
    }

    // recursive case
    Triple left = isBSTEfficient(root->left);
    Triple right = isBSTEfficient(root->right);

    bool isRootBST = root->val > left.maxValue && root->val < right.minValue;

    t.isBST = left.isBST && right.isBST && isRootBST;
    t.maxValue = max(left.maxValue, max(right.maxValue, root->val));
    t.minValue = min(left.minValue, min(right.minValue, root->val));

    return t;
}

bool isBSTEfficientRange(TreeNode* root, long long lb, long long ub) {
    // base case
    if(!root)
        return true;

    // recursive case

    return root->val > lb && root->val < ub && isBSTEfficientRange(root->left, lb, root->val) && isBSTEfficientRange(root->right, root->val, ub);
}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(18);

	isBST(root) ? cout << "true" << endl : cout << "false" << endl;

	Triple t = isBSTEfficient(root);

	t.isBST ? cout << "true" << endl : cout << "false" << endl;

	// long long lb = (long long)INT_MIN - 1;
	// long long ub = (long long)INT_MAX + 1;

	long long lb = LLONG_MIN; // -2^63
	long long ub = LLONG_MAX; // 2^63 - 1

	isBSTEfficientRange(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}