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

bool flag = false;

void generatePath(TreeNode* root, int target, vector<int> vec) {
    // base case
    if(!root)
        return;

    if(root->val == target) {
        vec.push_back(root->val);
        flag = true;

        for(int v: vec)
            cout << v << " ";
        cout << endl;

        vec.pop_back();

        return;
    }

    // recursive case
    vec.push_back(root->val);
    generatePath(root->left, target, vec);

    if(flag)
        return;

    generatePath(root->right, target, vec);
    vec.pop_back();
}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(2);

	root->left = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(9);
	root->left->right = new TreeNode(8);

	root->right = new TreeNode(6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	int target = 5;
    vector<int> vec;

	generatePath(root, target, vec);

	return 0;
}