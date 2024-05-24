#include<iostream>
#include<climits>
using namespace std;

// Time: O(n^3)
int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum = INT_MIN;

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum;

    return 0;
}