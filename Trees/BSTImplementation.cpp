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


void printInOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	printInOrder(root->left);
	cout << root->val << " ";
	printInOrder(root->right);
}

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

TreeNode* insert(TreeNode* root, int val) {
    // base case
    if(!root)
        return new TreeNode(val);

    // recursive case
    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

bool search(TreeNode* root, int key) {
    // base case
    if(!root)
        return false;

    if(root->val == key)
        return true;

    // recursive case
    if(key < root->val)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {

	TreeNode* root = NULL;

	root = insert(root, 10);

	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 7);

	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 17);

	printLevelOrder(root);

	cout << endl;

	printInOrder(root); // inOrder of a BST is always sorted

	cout << endl;

    search(root, 20) ? cout << "true" << endl :
	                        cout << "false" << endl;

	search(root, 7) ? cout << "true" << endl :
	                       cout << "false" << endl;

                           
	return 0;
}