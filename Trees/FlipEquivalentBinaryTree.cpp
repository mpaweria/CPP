#include<iostream>
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

bool areEquivalent(TreeNode* root1, TreeNode* root2) {
    // base case
    if(!root1 && !root2)
        return true;

    if(!root1)
        return false;
    
    if(!root2)
        return false;

    if(root1->val != root2->val)
        return false;

    // recursive case
    swap(root1->left, root1->right);
    if (areEquivalent(root1->left, root2->left) && areEquivalent(root1->right, root2->right))
        return true;

    swap(root1->left, root1->right);
    if (areEquivalent(root1->left, root2->left) && areEquivalent(root1->right, root2->right))
        return true;

    return false;
}

int main() {

	TreeNode* root1 = NULL, *root2 = NULL;

    cout << "Enter pre-order of tree: ";
	root1 = buildTree();
    root2 = buildTree();

	printPreOrder(root1);
    cout << endl;
    printPreOrder(root2);

	cout << endl << "Are trees equivalent: "; 
    areEquivalent(root1, root2) ? cout << "true" : cout << "false" << endl;

	return 0;
}