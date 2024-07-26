#include<iostream>
#include<unordered_map>

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

int helper(TreeNode* root) {
    // base case
    if(!root)
        return 0;

    // recursive case
    int dontRob = helper(root->left) + helper(root->right);

    int rob = root->val;

    if(root->left) {
        rob += helper(root->left->left) + helper(root->left->right);
    }
    if(root->right) {
        rob += helper(root->right->left) + helper(root->right->right);
    }

    return max(rob, dontRob);
}

int helperTopDown(TreeNode* root, unordered_map<TreeNode*, int> dp) {
    // lookup
    if(dp.find(root) != dp.end())
        return dp[root];

    // base case
    if(!root)
        return dp[root] = 0;

    // recursive case
    int dontRob = helperTopDown(root->left, dp) + helperTopDown(root->right, dp);

    int rob = root->val;

    if(root->left) {
        rob += helperTopDown(root->left->left, dp) + helperTopDown(root->left->right, dp);
    }
    if(root->right) {
        rob += helperTopDown(root->right->left, dp) + helperTopDown(root->right->right, dp);
    }

    return dp[root] = max(rob, dontRob);
}

int rob(TreeNode* root) {
    // return helper(root);

    unordered_map<TreeNode*, int> dp;
    return helperTopDown(root, dp);
}

int main() {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << rob(root) << endl;

    // TreeNode* root = new TreeNode(3);

    // root->left = new TreeNode(4);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);

    // root->right = new TreeNode(5);
    // root->right->right = new TreeNode(1);

    // cout << rob(root) << endl;

    return 0;
}