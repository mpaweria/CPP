#include <iostream>
#include<vector>
using namespace std;

int main() {
    vector<string> vec = {"abc", "abcd", "axyz", "axyz"};
    string largest = vec[0];
    for(int i=1; i<vec.size(); i++) {
        for(int j=0; j<vec[i].size(); j++) {
            if(j < largest.length() && largest[j] < vec[i][j]) {
                largest = vec[i];
                continue;
            }
            if(vec[i].size() > largest.length()) {
                largest = vec[i];
            }
        }
    }
    cout << largest << endl;

    return 0;
}