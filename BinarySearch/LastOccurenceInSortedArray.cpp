#include<iostream>
using namespace std;

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
    int n = 8, t = 30;
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};

    cout << "Last occurence of " << t << " in array is at index " << upperBound(arr, n, t);

    return 0;
}