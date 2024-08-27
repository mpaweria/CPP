#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* srcNode) {
    if (srcNode == NULL) {
        return NULL;
    }
    
    unordered_map<Node*, Node*> cloneMap;
    queue<Node*> q;

    Node* srcClone = new Node(srcNode->val);
    cloneMap[srcNode] = srcClone;
    q.push(srcNode);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        Node* frontClone = cloneMap[front];

        vector<Node*> neighbourList = front->neighbors;
        for(Node* neighbour: neighbourList) {
            if(cloneMap.find(neighbour) == cloneMap.end()) {
                Node* neighbourClone = new Node(neighbour->val);
                cloneMap[neighbour] = neighbourClone;
                q.push(neighbour);
            }
            frontClone->neighbors.push_back(cloneMap[neighbour]);
        }
    }
    return srcClone;
}

// Submitted on LeetCode: leetcode.com/problems/clone-graph/