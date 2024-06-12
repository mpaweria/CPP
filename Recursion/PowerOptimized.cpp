#include<iostream>
using namespace std;

int power(int x, int y) {
    // base case
    if(y == 0)
        return  1;

    // recrusive case
    int pow = power(x, y/2);
    if(y % 2 == 0) {
        return pow * pow;
    }
    return pow * pow * x;
}

int main() {
    int x = 3, y = 3;

    cout << power(x, y);

    return 0;
}