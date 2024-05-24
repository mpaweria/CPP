#include<iostream>
using namespace std;

bool isGoodString(const string &str) {
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        if(!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            return false;
        }
    }
    return true;
}

int main() {
    string str = "aiiou";

    cout << isGoodString(str);

    return 0;
}