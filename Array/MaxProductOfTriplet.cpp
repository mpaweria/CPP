#include<iostream>
#include<climits>
using namespace std;

int main () {
    int n = 5;
    int arr[n] = {20, 25, 15, 10, 0};
    int firstLargest = INT_MIN, secondLargest = INT_MIN, thirdLargest = INT_MIN, firstSmallest = INT_MAX, secondSmallest = INT_MAX, product = 1;

    for(int i=0; i<n; i++) {
        if(arr[i] > firstLargest) {
            thirdLargest = secondLargest;
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if(arr[i] > secondLargest) {
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        } else if(arr[i] > thirdLargest) {
            thirdLargest = arr[i];
        }
        if(arr[i] < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        } else if(arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }
    }
    product = max((firstLargest * secondLargest * thirdLargest), (firstLargest * firstSmallest * secondSmallest));
    cout << product;

    return 0;
}