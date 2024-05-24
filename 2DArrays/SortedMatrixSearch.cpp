#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> vec = {{40, 50, 60},
                               {10, 20, 30},
                               {70, 80, 90}};
    int target = 70;

    for(int i=0; i<vec.size(); i++) {
        int s=0, e=vec[0].size()-1;
        while (s <= e)
        {
            int mid = s + (e-s)/2;
            if(vec[i][mid] == target) {
                cout << "true";
                return 0;
            } else if(vec[i][mid] < target) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }        
    }
    cout << "false";
    return 0;
}