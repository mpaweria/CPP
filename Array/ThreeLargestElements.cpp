#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n = 6;
    int arr[n] = {20, 5, 0, 25, 15, 10};
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for(int i=0; i<n; i++) {
        if(arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if(arr[i] > second) {
            third = second;
            second = arr[i];
        } else if(arr[i] > third) {
            third = arr[i];
        }
    }

    cout << third << " " << second << " " << first;

    return 0;
}