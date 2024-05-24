#include<iostream>
using namespace std;

int lowerBound(int arr[], int n, int t) {
    int s = 0, e = n-1, minIdx = -1;

    while(s <= e) {
        int mid = s + (e - s)/2;
        if(arr[mid] == t) {
            minIdx = mid;
            e = mid-1;
        } else if(arr[mid] > t)
            e = mid-1;
        else
            s = mid+1;
    }
    return minIdx;
}

int upperBound(int arr[], int n, int t) {
    int s = 0, e = n-1, lastIdx = -1;

    while(s <= e) {
        int mid = s + (e - s)/2;
        if(arr[mid] == t){
            lastIdx = mid;
            s = mid + 1;
        } else if(arr[mid] < t) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return lastIdx;
}

int main() {
    int n = 8, t = 100;
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};

    int count = lowerBound(arr, n, t) == -1 ? 0 : (upperBound(arr, n, t) - lowerBound(arr, n, t)) + 1;

    cout << t << " occurs in the array " << count << " times.";

    return 0;
}