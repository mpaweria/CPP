#include<iostream>
using namespace std;

// Time: O(n1+n2)
// Space: O(1) since we are modifying arr1 only
void mergeArrays(int arr1[], int arr2[], int n1, int n2) {
    int i = n1-1, j = n2-1, k = n1+n2-1;

    while(i >= 0 && j >= 0) {
        if(arr1[i] > arr2[j]){
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }
    while (j >= 0)
    {
        arr1[k--] = arr2[j--];
    }
}

int main() {
    int n1 = 4, n2 = 3;
    int arr1[n1+n2] = {10, 30, 50, 70}, arr2[] = {20, 40, 60};

    mergeArrays(arr1, arr2, n1, n2);

    for(int i=0; i<n1+n2; i++) {
        cout << arr1[i] << " ";
    }

    return 0;
}