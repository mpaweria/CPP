#include<iostream>
using namespace std;

int targetSumPairs(int arr[], int n, int t) {
    int s = 0, e = n-1, pairs = 0;

    while(s < e) {
        int sum = arr[s] + arr[e];
        if(sum == t) {
            pairs++;
            s++;
            e--;
        } else if(sum < t) {
            s++;
        } else {
            e--;
        }
    }   
    return pairs;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int t = 60, n = 6;

    cout << targetSumPairs(arr, n, t);

    return 0;
}