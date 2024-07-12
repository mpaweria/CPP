// 1 2 4 -1 -1 -1 3 2 4 -1 -1 -1 4 -1 -1 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

node* buildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		node* root = NULL;
		// root represents an empty tree
		return root;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

string findDuplicateSubtrees(node* root, set<node*> &s, unordered_map<string, node*> &map) {
    // base case
    if(!root)
        return "-";

    // recursive case
    string leftSubtree = findDuplicateSubtrees(root->left, s, map), rightSubtree = findDuplicateSubtrees(root->right, s, map);

    string treeRepr = to_string(root->data) + " " + leftSubtree + " " + rightSubtree;

    if(map.find(treeRepr) != map.end()) {
        s.insert(map[treeRepr]);
    } else {
        map[treeRepr] = root;
    }

    return treeRepr;
}

int main() {
    node* root = NULL;
	root = buildTree();

    set<node*> set;
    unordered_map<string, node*> map;

    findDuplicateSubtrees(root, set, map);

    for(auto s: set) {
        cout << s->data << " ";
    }

    return 0;
}