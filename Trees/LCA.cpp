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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // base case
    if(!root)
        return NULL;

    if(root == p || root == q)
        return root;

    // recursive case
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left && right)
        return root;
    else if(left)
        return left;
    else if(right)
        return right;

    return NULL;
}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(3);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	root->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

    TreeNode* LCA = lowestCommonAncestor(root, root->left->right->left, root->left->left);  // p = 7, q = 6

    cout << "Lowest Common Ancestor is: " << LCA->val;

	return 0;
}