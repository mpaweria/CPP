#include<iostream>
using namespace std;

void allOccurence(int arr[], int i, int n, int t, bool isPresent) {
    // base case
    if(i == n) {
        if(!isPresent)
            cout << -1;
        return;
    }

    // recursive case
    if(arr[i] == t){
        cout << i << " ";
        isPresent = true;
    }

    allOccurence(arr, i+1, n, t, isPresent);
}

int main() {
    int n = 8, t = 30;
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};

    cout << t << " is present at indicies ";
    allOccurence(arr, 0, n, t, false);

    return 0;
}