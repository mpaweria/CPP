#include<iostream>
using namespace std;

int main() {
    int num1 = 42 , num2 = 36, count = 0;
    int num = num1 ^ num2;

    while (num)
    {
        count++;
        num = num & num-1;
    }
    cout << "Hamming distance is: " << count;

    return 0;
}