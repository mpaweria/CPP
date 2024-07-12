#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

bool isDuplicatePresent(vector<int> v, int n) {
    unordered_map<int, int> map;

    for(int i: v) {
        map[i]++;
    }

    for(auto p: map){
        if(p.second > 1)
            return true;
    }
    return false;
}

bool isDuplicatePresentUsingSet(vector<int> v, int n) {
    unordered_set<int> set;

    for(int i: v){
        if(set.find(i) != set.end())
            return true;
        set.insert(i);
    }
    return false;
}

int main() {

	vector<int> v = {1, 2, 3, 4, 1, 2};
	int n = v.size();

	isDuplicatePresent(v, n) ? cout << "duplicate found" << endl : cout << "no duplicates" << endl;

	isDuplicatePresentUsingSet(v, n) ? cout << "duplicate found" << endl : cout << "no duplicates" << endl;

	return 0;
}