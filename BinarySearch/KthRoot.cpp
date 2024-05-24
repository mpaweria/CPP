#include<iostream>
#include<cmath>
using namespace std;

float kthRoot(int n, int p, int k) {
    int s = 0, e = n;
    float krt = 0;
    while (s <= e)
    {
        int m = s + (e - s)/2;
        if(pow(m,k) <= n) {
            krt = m;
            s = m+1;
        } else {
            e = m-1;
        }
    }
    float inc = 0.1;

    for(int i=0; i<p; i++) {
        while (pow(krt,k) <= n)
        {
            krt = krt + inc;
        }
        krt = krt - inc;
        inc = inc / 10;
    }
    return krt;
}

int main() {
    int n = 16, p = 3, k = 4;

    cout << kthRoot(n, p, k);

    return 0;
}