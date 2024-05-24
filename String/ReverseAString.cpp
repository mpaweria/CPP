#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str[] = "hello!";
    int i = 0, j= strlen(str) - 1;

    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    cout << str;

    return 0;
}