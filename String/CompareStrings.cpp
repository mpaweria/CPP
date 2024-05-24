#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str1[] = "abc", str2[] = "adc";

    if (strlen(str1) > strlen(str2)) {
        cout << 1;
    } else if(strlen(str1) < strlen(str2)) {
        cout << -1;
    } else {
        int i=0, flag = 1;
        while (i < strlen(str1))
        {
            if (str1[i] > str2[i]) {
                cout << 1;
                flag = 0;
                break;
            } else if (str1[i] < str2[i]) {
                cout << -1;
                flag = 0;
                break;
            } 
            i++;
        }
        if(flag)
            cout << 0;
    }

    return 0;
}