#include<iostream>
using namespace std;

float squareRoot(int n, int p) {
    int s = 0, e = n;
    float sqr;
    while (s <= e)
    {
        int m = s + (e - s)/2;
        if(m * m <= n) {
            sqr = m;
            s = m+1;
        }
        else
            e = m-1;   
    }

    float inc = 0.1;
    for(int i=0; i<p; i++) {
        while (sqr * sqr <= n)
        {
            sqr = sqr + inc;
        }
        sqr = sqr - inc;
        inc = inc/10;
    }
    return sqr;
}

int main() {
    int n = 68, p = 2;
    cout << squareRoot(n, p);

    return 0;
}