#include<iostream>
#include<vector>
using namespace std;

void generatePermutations(int t, vector<int>& c, vector<int>& perm) {
    // base case
    if(t == 0) {
        for(int i: perm)
            cout << i << " ";
        cout << endl;
        return;
    }

    // recursive case
    for(int i: c) {
        if(i <= t) {
            perm.push_back(i);
            generatePermutations(t-i, c, perm);
            perm.pop_back();
        }
    }
}

int main() {
	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> perm; // to track the permutation that sums up to 't'

	generatePermutations(t, c, perm);

	return 0;
}