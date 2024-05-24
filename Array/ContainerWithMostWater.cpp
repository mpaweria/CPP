#include<iostream>
using namespace std;

// Brute force approach isto generate pair and calculate area which will take O(n^2)
// Time O(n)
int maxWater(int arr[], int n) {
    int s = 0, e = n-1, maxArea = 0;

    while (s < e) {
        int area  = min(arr[s], arr[e]) * (e - s);
        maxArea = max(maxArea, area);
        if(arr[s] < arr[e])
            s++;
        else
            e--;
    }
    return maxArea;
}

int main() {
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = 9;

    cout << maxWater(arr, n);

    return 0;
}