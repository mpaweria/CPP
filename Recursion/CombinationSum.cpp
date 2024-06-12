#include<iostream>
#include<vector>
using namespace std;

void generateCombinations(int t, vector<int>& c, vector<int>& comb, int i) {
    // base case
    if(t == 0) {
        for(int j: comb)
            cout << j << " ";
        cout << endl;
        return;
    }

    // recursive case
    for(int j = i; j < c.size(); j++) {
        if(c[j] <= t) {
            comb.push_back(c[j]);
            generateCombinations(t-c[j], c, comb, j);
            comb.pop_back();
        }
    }
}

int main() {
	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> comb; // to track the combination that sums up to 't'

	generateCombinations(t, c, comb, 0);

	return 0;
}