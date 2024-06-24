/*

	Given a BST, design an algorithm transform it into a sorted linked list in-place.

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
		this->left = this->right = NULL;
	}
};


void printLinkedList(TreeNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->right;
	}

	cout << endl;
}

class Pair {
public:
	TreeNode* head;
	TreeNode* tail;
};

Pair convert(TreeNode* root) {
    Pair p;

    // base case
    if(!root)
        return {NULL, NULL};

    // recursive case
    Pair left = convert(root->left);
    if(!left.head)
        left.head = root;
    else
        left.tail->right = root;

    Pair right = convert(root->right);
    if(!right.tail)
        right.tail = root;
    else
        root->right = right.head;

    return {left.head, right.tail};
}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	Pair p = convert(root);

	printLinkedList(p.head);

	return 0;
}