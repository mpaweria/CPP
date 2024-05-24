#include<iostream>
using namespace std;

int main() {
    int n = 7, i = 2, j = 5;  //swap the numbers b/w i and j
    int arr[n] = {10, 20, 30, 40, 50, 60, 70};

    cout << "Initial Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    while(i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    cout << endl << "Reversed Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}