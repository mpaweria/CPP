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

class Triple {
public :

	int numCameras;
	bool isCovered;
	bool hasCamera;

};

Triple helper(TreeNode* root) {
    // base case
    if(!root)
        return {0, true, false};

    // recursive case
    Triple ans;

    Triple left = helper(root->left);
    Triple right = helper(root->right);

    if(!left.isCovered || !right.isCovered) {
        ans.numCameras = left.numCameras + right.numCameras + 1;
        ans.isCovered = true;
        ans.hasCamera = true;

        return ans;
    }
    ans.numCameras = left.numCameras + right.numCameras;
    ans.hasCamera = false;
    ans.isCovered = left.hasCamera || right.hasCamera;

    return ans;
}

int minCameraCover (TreeNode* root) {
    Triple ans = helper(root);

    if(!ans.isCovered)
        return 1 + ans.numCameras;

    return ans.numCameras;
}

int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// root->right = new TreeNode(0);
	// root->right->left = new TreeNode(0);
	// root->right->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	TreeNode* newRoot = new TreeNode(0);

	root = new TreeNode(0);

	newRoot->left = root;

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	root->right = new TreeNode(0);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(0);

	cout << minCameraCover(newRoot) << endl;


	return 0;
}