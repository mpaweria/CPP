#include<iostream>
using namespace std;

void generateSubstrings(const string &str, int n) {
    for(int l=1; l<=n; l++) {
        for(int i=0; i<=n-l; i++) {
            cout << str.substr(i, l) << endl;
        }
    }
}

int main() {
    string str = "abcde";
    int n = str.length();

    generateSubstrings(str, n);

    return 0;
}