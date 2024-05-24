#include<iostream>
using namespace std;

int main() {
    int n = 15, count = 0, count2 = 0;
    int num = n;

    // this loop will run log(n) times
    while(n) {
        if(n & 1)
            count++;
        n = n >> 1;
    }
    cout << "Number of set bits in " << num << " are " << count << endl; 

    // this loop will only run the number of set bits times
    n = num;
    while(n) {
        count2++;
        n = n & n-1;
    }
    cout << "Number of set bits in " << num << " are " << count2; 

    return 0;
}