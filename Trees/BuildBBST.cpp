/*

	Given a inOrder traversal of a BST, design an algorithm to build a balanced BST.

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

TreeNode* buildBBST(int arr[], int s, int e) {
    // base case
    if(s > e)
        return NULL;

    // recursive case
    int mid = s + (e - s)/2;
    int rootVal = arr[mid];

    TreeNode* root = new TreeNode(rootVal);

    root->left = buildBBST(arr, s, mid-1);
    root->right = buildBBST(arr, mid+1, e);

    return root;
}

int main() {

	int arr[] = {3, 5, 7, 10, 13, 15, 17};
	int n = sizeof(arr) / sizeof(int);

	TreeNode* root = buildBBST(arr, 0, n - 1);

	printLevelOrder(root);

	cout << endl;

	return 0;
}