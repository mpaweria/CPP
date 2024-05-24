#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

bool compare(int a, int b) {
    string str1 = to_string(a);
    string str2 = to_string(b);

    return str1+str2 > str2+str1;
}

string biggestNumber(vector<int> vec, int n) {

    sort(vec.begin(), vec.end(), compare);

    string res = "";

    for(int i=0; i<n; i++) {
        res += to_string(vec[i]);
    }

    return res;
}

int main() {
    // vector<int> vec = {54, 546, 548, 60};
    vector<int> vec = {98, 9, 78, 8};

    cout << biggestNumber(vec, vec.size());

    return 0;
}