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

int main() {
    int n = 8, t = 30;
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};

    cout << "First occurence of " << t << " in array is at index " << lowerBound(arr, n, t);

    return 0;
}