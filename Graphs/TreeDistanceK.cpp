/**
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, list<TreeNode*>> neighbourMap;

        q.push(root);

        while (!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front->left) {
                neighbourMap[front].push_back(front->left);
                neighbourMap[front->left].push_back(front);
                q.push(front->left);
            }

            if(front->right) {
                neighbourMap[front].push_back(front->right);
                neighbourMap[front->right].push_back(front);
                q.push(front->right);
            }
        }

        unordered_map<TreeNode*, int> distMap;
        distMap[target] = 0;

        q.push(target);

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            list<TreeNode*> neighbourList = neighbourMap[front];

            for(TreeNode* neighbour: neighbourList) {
                if(distMap.find(neighbour) == distMap.end()) {
                    distMap[neighbour] = distMap[front] + 1;
                    q.push(neighbour); 
                }
            }
        }
        vector<int> out;
        for (pair<TreeNode*, int> p : distMap) {
            TreeNode* node = p.first;
            int distance = p.second;
            if (distance == k) {
                out.push_back(node->val);
            }
        }

        return out;
    }
};