#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> vec = {{50, 80, 20},
                               {90, 10, 70},
                               {60, 30, 40}};
    int target = 100;

    for(int i=0; i<vec.size(); i++) {
        for(int j=0; j<vec.size(); j++) {
            if(vec[i][j] == target) {
                cout << "true";
                return 0;
            }
        }
    }
    cout << "false";

    return 0;
}