#include<iostream>
#include<vector>
using namespace std;

// Time: O(m+n)  m=vec.size(), n = vec[0].size()
int main() {
    vector<vector<int>> vec = {{10, 20, 30},
                               {40, 50, 60},
                               {70, 80, 90}};
    int target = 80;

    int s = 0, e = vec[0].size()-1;
    while (s <= vec.size()-1 && e >= 0) {
        if(vec[s][e] == target) {
            cout << "true";
            return 0;
        } else if(vec[s][e] < target) {
            s++;
        } else {
            e--;
        }
    }
        
    cout << "false";
    return 0;
}