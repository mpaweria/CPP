#include<iostream>
#define ll long long
using namespace std;

string s;         // to store the hamburger's recipe
int nb, ns, nc;   // to store the inventory of 'B', 'S' and 'C'
int pb, ps, pc;   // to store the price of 'B', 'S' and 'C'
int cb, cs, cc;   // to store the frequencies of 'B', 'S' and 'C' hamburger's recipe
ll r;             // to store the money Polycarpus has

bool canPolyCarpusCook(ll m) {
    ll eb = max((ll)0, m*cb-nb);
    ll es = max((ll)0, m*cs-ns);
    ll ec = max((ll)0, m*cc-nc);

    ll er = (pb*eb) + (ps*es) + (pc*ec);

    return r >= er;
}

int main() {
    s = "BBBSSC";
    nb = 6; 
    ns = 4; 
    nc = 1;

    pb = 1;
    ps = 2;
    pc = 3;

    r = 4;

    for (char c : s) {
        if (c == 'B') cb++;
        else if (c == 'S') cs++;
        else if (c == 'C') cc++;
    }

    ll s = 0;
    ll e = 1e12 + 100;
    ll ans = 0;

    while(s<=e) {
        ll m = s + (e - s)/2;
        if(canPolyCarpusCook(m)) {
            ans = m;
            s = m+1;
        } else {
            e = m-1;
        }
    }

    cout << ans;

    return 0;
}