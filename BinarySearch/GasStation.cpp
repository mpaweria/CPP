#include<iostream>
#include<cmath>
using namespace std;

bool isPossible(int stations[], int n, int k, double m) {
    double count = 0;
    for(int i=0; i<n-1; i++) {
        int d = stations[i+1] - stations[i];
        count += ceil(d/m)-1;
    }
    return count <= k;
}

double minMaxDistance(int stations[], int n, int k) {

    int minSoFar = 0;
    for(int i=0; i<n-1; i++) {
        if(stations[i+1] - stations[i] < minSoFar) {
            minSoFar = stations[i+1] - stations[i];
        }
    }

    double s = (double)minSoFar/(k+1), e = (double)(stations[n-1] - stations[0])/(k+1), ans = 0;

    while (e - s > 1e-6)
    {
        double m = s + (e - s)/2;
        if(isPossible(stations, n, k, m)) {
            ans = m;
            e = m;
        } else {
            s = m;
        }
    }
    return ans;
}

int main() {
    int stations[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9, n = 10;

    cout << minMaxDistance(stations, n, k);

    return 0;
}