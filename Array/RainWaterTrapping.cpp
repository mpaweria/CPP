#include<iostream>
using namespace std;

int trapWater(int arr[], int n) {
    int s=0, e=n-1, l=0, r=0, total = 0;

    while(s <= e) {
        l = max(l, arr[s]);
        r = max(r, arr[e]);

        if(l < r) {
            int w = l - arr[s];
            total += w;
            s++;
        } else {
            int w = r - arr[e];
            total += w;
            e--;
        }
    }
    return total;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = 12;

    cout << trapWater(arr, n);

    return 0;
}