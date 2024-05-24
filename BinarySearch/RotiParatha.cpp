#include<iostream>
#include<climits>
using namespace std;

int numberOfParaathsCookedByOneCook(int r, int m) {
    int count = 0, time = 0, n = 1;
    while (true)
    {
        time += n*r;
        if(time > m) {
            break;
        }
        count++;
        n++;
    }
    return count;
}

int numberOfParaathsCooked(int* ranks, int l, int m) {
    int parathaCooked = 0;
    
    for(int i=0; i<l; i++) {
        parathaCooked += numberOfParaathsCookedByOneCook(ranks[i], m);
    }

    return parathaCooked;
}

int main() {
    int p = 8, l = 4, s = 0, e = INT_MAX, ans = 0;
    int ranks[] = {1, 2, 3, 4};

    while(s <= e) {
        int m = s + (e - s)/2;
        int parathas = numberOfParaathsCooked(ranks, l, m);
        
        if(parathas >= p) {
            ans = m;
            e = m-1;
        } else {
            s = m+1;
        }
    }
    cout << ans;

    return 0;
}