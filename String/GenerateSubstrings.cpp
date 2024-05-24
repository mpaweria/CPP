#include<iostream>
using namespace std;

void generateSubstring(const string &str, int n) {
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            for(int k=i; k<=j; k++) {
                cout << str[k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    string str = "abcde";
    int n = str.size();

    generateSubstring(str, n);

    return 0;
}