#include<iostream>
using namespace std;

int main() {
    char str[] =  "coding blocks";
    int count = 0, i = 0;

    while(str[i++] != '\0') {
        count++;
    }
    cout << "Length of " << str << " is " << count << endl;

    return 0;
}