#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v = {1, 0, 1, 1, 1, 2, 3, 3, 4};
	int n = v.size();

    for(int i=0; i<n; i++) {
        int x = v[i]%n;
        v[x] += n;
    }

    for(int i=0; i<n; i++) {
        if(v[i]/n > 1)
            cout << i << " ";
    }

    return 0;
}