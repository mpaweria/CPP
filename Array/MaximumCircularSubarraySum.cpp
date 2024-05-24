#include<iostream>
using namespace std;

// To calculate maximum circular sum, we can calculate the minimum subarray sum and subtract it from total sum which will give us maximum subarray sum
int minSubarraySum(int arr[], int n) {
    int minSum = arr[0], sum = arr[0];

    for(int i=1; i<n; i++) {
        sum = min(sum + arr[i], arr[i]);
        minSum = min(minSum, sum);
    }
    return minSum;
}

int maxSubarraySum(int arr[], int n) {
    int maxSum = arr[0], sum = arr[0];

    for(int i=1; i<n; i++) {
        sum = max(sum + arr[i] , arr[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int totalSubarraySum(int arr[], int n) {
    int totalSum = arr[0];

    for(int i=1; i<n; i++){
        totalSum += arr[i];
    }
    return totalSum;
}

int maxCircularSubarraySum(int arr[], int n) {
    int totalSum = totalSubarraySum(arr, n);
    int maxSum = maxSubarraySum(arr, n);
    int minSum = minSubarraySum(arr, n);

    return totalSum == minSum ? maxSum : totalSum - minSum;
}

int main() {
    // int arr[] = {-3, -2, -3};
    // int arr[] = {-1,-2, -3, 1, 2, 3};
    int arr[] = {1, 2, -3, -4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxCircularSubarraySum(arr, n);
}