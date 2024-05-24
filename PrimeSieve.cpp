#include<iostream>
using namespace std;

int main() {
    int n = 100;
    int arr[n+1];

    for(int i=0; i<=n; i++) {
        arr[i] = 1;
    }
    arr[0] = arr[1] = 0;

    // 1st Approach
    // for(int i=2; i<=n; i++) {
    //     if(arr[i] == 1) {
    //         for(int j=i*2; j<=n; j+=i) {
    //             arr[j] = 0;
    //         }
    //     } 
    // }

    // 2nd Approach
    // for(int i=2; i<=n; i++) {
    //     if(arr[i] == 1) {
         // the multiple of i from 1*2 - i^-1 are cancelled out by previous numbers, so we can start from i*i
    //         for(int j=i*i; j<=n; j+=i) {
    //             arr[j] = 0;
    //         }
    //     } 
    // }


    // 3rd Approach
    // All the composite number will be cancelled out by numbers before sqrt(n)
    for(int i=2; i*i<=n; i++) { // i    <= sqrt(n)
        if(arr[i] == 1) {
            for(int j=i*i; j<=n; j+=i) {
                arr[j] = 0;
            }
        } 
    }

    for(int i=2; i<=n; i++) {
        if(arr[i])
            cout << i << " ";
    }
}