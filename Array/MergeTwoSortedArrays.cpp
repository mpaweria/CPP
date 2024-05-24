#include<iostream>
using namespace std;

// Time: O(n1+n2)
// Space: O(n1+n2)
void mergeArrays(int arr1[], int arr2[], int n1, int n2) {
    int i=0, j=0, k=0;
    int res[n1+n2];

    while(i<n1 && j<n2) {
        if(arr1[i] < arr2[j])
            res[k++] = arr1[i++];
        else
            res[k++] = arr2[j++];
    }
    while(i<n1) {
        res[k++] = arr1[i++];
    }
    while(j<n2) {
        res[k++] = arr2[j++];
    }

    for(int k=0; k<n1+n2; k++) {
        cout << res[k] << " ";
    } 
}

int main() {
    int arr1[] = {10, 30, 50, 70}, arr2[] = {20, 40, 60};
    int n1 = 4, n2 = 3;

    mergeArrays(arr1, arr2, n1, n2);

    return 0;
}