/*
eg: preOrder : 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 5 -1 -1 1 -1 -1
*/

#include<iostream>
#include<vector>
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

void printPath(TreeNode* root, int target, vector<int> vec) {
    // base case
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL) {
        if(root->val == target) {
            vec.push_back(root->val);

            for(int v: vec)
                cout << v << " ";

            cout << endl;

            vec.pop_back();
        }
        return;
    }

    // recursive case
    vec.push_back(root->val);
    printPath(root->left, target-root->val, vec);
    printPath(root->right, target-root->val, vec);
    vec.pop_back();
}

int main() {

	TreeNode* root = NULL;

    cout << "Enter pre-order of tree: ";
	root = buildTree();

	printPreOrder(root);

	cout << endl;

    int target = 22;
    vector<int> vec;
    cout << "Following paths exist:" << endl;
    printPath(root, target, vec);

	return 0;
}