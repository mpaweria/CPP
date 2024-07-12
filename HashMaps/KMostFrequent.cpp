#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
    vector<int> vec = {10, 10, 10, 20, 20, 30, 40, 50, 50, 60, 60, 60};
    int n = vec.size();
    int k = 3;
    
    unordered_map<int, int> map;

    for(int v: vec)
        map[v]++;

    
    vector<vector<int>> v(n+1);

    for(auto m: map) {
        v[m.second].push_back(m.first);
    }

    bool flag = false;

    for(int i=n-1; i>=0; i--) {
        vector<int> temp = v[i];

        for(int j=0; j<temp.size(); j++) {
            cout << temp[j] << " ";
            k--;

            if(k == 0) {
                flag = true;
                break;;
            }
        }
        if(flag)
            break;
    }
    return 0;
}