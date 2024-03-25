#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// Basic Recursive Solution 
// Time Complexity - O(3^n)
// Space Complexity - O(n) due to recursive calls
int minStepsToOne(int num) {
    // base case
    if(num == 1)
        return 0;

    // recursive case
    int divBy2 = INT_MAX, divBy3 = INT_MAX;
    if(num % 2 == 0)
        divBy2 = minStepsToOne(num/2);
    
    if(num % 3 == 0)
        divBy3 = minStepsToOne(num/3);

    return 1 + min(minStepsToOne(num-1), min(divBy2, divBy3));
}

// Dynamic Programming Top Down
// Time Complexity - O(n)
// Space Complexity - O(n) due to dp[] + function call stack
int minStepsToOneTopDown(int num, vector<int>& dp) {
    //look up
    if(dp[num] != -1)
        return dp[num];

    // base case
    if(num == 1)
        return dp[num] = 0;

    // recursive case
    int divBy2 = INT_MAX, divBy3 = INT_MAX;
    if(num % 2 == 0)
        divBy2 = minStepsToOne(num/2);
    
    if(num % 3 == 0)
        divBy3 = minStepsToOne(num/3);

    return dp[num] = 1 + min(minStepsToOne(num-1), min(divBy2, divBy3));
}

// Dynamic Programming Bottom Up
// Time Complexity - O(n)
// Space Complexity - O(n) due to dp[]
int minStepsToOneBottomUp(int num) {
    vector<int> dp(num+1, -1);
    
    dp[1] = 0;

    for(int i=2; i<=num; i++){
        int divBy2 = INT_MAX, divBy3 = INT_MAX;
        if(i%2 == 0)
            divBy2 = dp[i/2];
        if(i%3 == 0)
            divBy3 = dp[i/3];

        dp[i] = 1+ min(dp[i-1], min(divBy2, divBy3));
    }
    return dp[num];
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    vector<int> dp(num+1, -1);

    cout << minStepsToOne(num) << endl;
    cout << minStepsToOneTopDown(num, dp) << endl;
    cout << minStepsToOneBottomUp(num) << endl;

    return 0;
}