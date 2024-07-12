#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isValid(vector<int> v, int k) {
    unordered_map<int, int> map;

    for(int i=0; i<v.size(); i++){
        if(map.find(v[i]) != map.end()){    
            if(i - map[v[i]] <= k)
                return true;
        }
        map[v[i]] = i;
    }

    return false;
}

int main() {

	vector<int> v = {1, 2, 3, 1, 2, 3};
	int k = 2;

	isValid(v, k) ? cout << "found a valid pair" << endl : cout << "no valid pair found" << endl;

	return 0;
}