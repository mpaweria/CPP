#include<iostream>
#include<vector>
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

int maxProfit(TreeNode* root) {
    // base case
    if(root == NULL)
        return 0;


    // recursive case
    int dontRob = maxProfit(root->left)+ maxProfit(root->right);

    int rob = root->val;

    if(root->left != NULL) {
        rob += maxProfit(root->left->left) + maxProfit(root->left->right);
    }
    if(root->right != NULL) {
        rob += maxProfit(root->right->left) + maxProfit(root->right->right);
    }

    return max(rob, dontRob);
}

int maxProfitTopDown(TreeNode* root, unordered_map<TreeNode*, int> dp) {
    // look up 
    if(dp.find(root) != dp.end())
        return dp[root];

    // base case
    if(root == NULL)
        return dp[root] = 0;

    // recursive case
    int dontRob = maxProfitTopDown(root->left, dp)+ maxProfitTopDown(root->right, dp);

    int rob = root->val;

    if(root->left != NULL) {
        rob += maxProfitTopDown(root->left->left, dp) + maxProfitTopDown(root->left->right, dp);
    }
    if(root->right != NULL) {
        rob += maxProfitTopDown(root->right->left, dp) + maxProfitTopDown(root->right->right, dp);
    }

    return dp[root] = max(rob, dontRob);
}

int main() {

    // TreeNode* root = new TreeNode(3);

    // root->left = new TreeNode(2);
    // root->left->right = new TreeNode(3);

    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);

    // unordered_map<TreeNode*, int> dp;

    // cout << maxProfit(root) << endl;
    // cout << maxProfitTopDown(root, dp);

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);    

    root->right = new TreeNode(5);
    root->right->right = new TreeNode(1);

    unordered_map<TreeNode*, int> dp;

    cout << maxProfit(root) << endl;
    cout << maxProfitTopDown(root, dp);

    return 0;
}