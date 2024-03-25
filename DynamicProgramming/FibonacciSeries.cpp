#include<iostream>
#include<vector>
using namespace std;

// Basic Recursive Solution 
// Time Complexity - O(2^n)
// Space Complexity - O(n) due to recursive calls
int fib(int num) {
    // base case
    if(num == 0 || num == 1)
        return num;

    // recursive case
        return fib(num-1) + fib(num-2);
}

// Dynamic Programming Top Down
// Time Complexity - O(n)
// Space Complexity - O(n) due to dp[] + function call stack
int fibTopDown(int num, vector<int>& dp) {
    // look up
    if(dp[num] != -1)
        return dp[num];

    // base case
    if(num == 0 || num == 1)
        return dp[num] = num;

    // recursive case
    return dp[num] = fibTopDown(num-1, dp) + fibTopDown(num-2, dp);
}

// Dynamic Programming Bottom Up
// Time Complexity - O(n)
// Space Complexity - O(n) due to dp[]
int fibBottomUp(int num){
    vector<int> dp(num+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=num; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[num];
}

// Dynamic Programming Bottom Up
// Time Complexity - O(n)
// Space Complexity - O(1) 
int fibBottomUpSpaceOptimized(int num) {
    if(num == 0 || num == 1)
        return num; 

    int first = 1, second = 0;

    for(int i=2; i<=num; i++){
        int temp = first + second;
        second = first;
        first = temp;
    }
    return first;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    vector<int> dp(num+1, -1);

    cout << fib(num) << endl;
    cout << fibTopDown(num, dp) << endl;
    cout << fibBottomUp(num) << endl;    
    cout << fibBottomUpSpaceOptimized(num) << endl;

    return 0;
}