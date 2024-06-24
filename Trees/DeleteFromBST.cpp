/*

	Given a BST and a key,  design an algorithm to delete
	the TreeNode with the given key, if present, from the BST.

*/

#include<iostream>
#include<queue>

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

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if (front->left) q.push(front->left);
			if (front->right)q.push(front->right);
		}
	}
}

void printInOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	printInOrder(root->left);
	cout << root->val << " ";
	printInOrder(root->right);
}

TreeNode* findMaximum(TreeNode* root) {
	if (!root) {
		return NULL;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root;
}

TreeNode* findMinimum(TreeNode* root) {
	if (!root) {
		return NULL;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root;
}

TreeNode* deleteFromBST(TreeNode* root, int key) {
    // base case
    if(!root)
        return NULL;

    // recursive case
    if(root->val == key) {

        if(!root->left && !root->right) {
            delete root;
            root = NULL;
        } else if(!root -> left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else  if(!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            TreeNode* leftMax = findMaximum(root->left);
            swap(root->val, leftMax->val);
            root->left = deleteFromBST(root->left, key);
        }

    } else if(key < root->val) {
        root->left = deleteFromBST(root->left, key);
    } else {
        root->right = deleteFromBST(root->right, key);
    }
    return root;
}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	printInOrder(root);
	cout << endl;

	printLevelOrder(root);
	cout << endl;

	int key = 3;

	root = deleteFromBST(root, key);

	printInOrder(root);
	cout << endl;

	printLevelOrder(root);
	cout << endl;

	key = 5;

	root = deleteFromBST(root, key);

	printInOrder(root);
	cout << endl;

	printLevelOrder(root);
	cout << endl;

	key = 10;

	root = deleteFromBST(root, key);

	printInOrder(root);
	cout << endl;

	printLevelOrder(root);
	cout << endl;


	return 0;
}