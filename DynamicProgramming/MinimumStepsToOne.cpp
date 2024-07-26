#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSteps(int n) {
    // base case
    if(n == 1)
        return 0;

    // recursive case
    int minusOne = minSteps(n-1);
    int divideByTwo = INT_MAX, divideByThree = INT_MAX;

    if(n % 2 == 0)
        divideByTwo = minSteps(n / 2);

    if(n % 3 == 0)
        divideByThree = minSteps(n / 3);

    return 1 + min(minusOne, min(divideByTwo, divideByThree));
}

int minStepsTopDown(int n, vector<int> &dp) {
    // look up
    if(dp[n] != -1)
        return dp[n];

    // base case
    if(n == 1)
        return dp[n] = 0;

    // recursive case
    int minusOne = minStepsTopDown(n-1, dp);
    int divideByTwo = INT_MAX, divideByThree = INT_MAX;

    if(n % 2 == 0)
        divideByTwo = minStepsTopDown(n / 2, dp);

    if(n % 3 == 0)
        divideByThree = minStepsTopDown(n / 3, dp);

    return dp[n] = 1 + min(minusOne, min(divideByTwo, divideByThree));
}

int minStepsBottomUp(int n) {
    vector<int> dp(n+1, 0);

    for(int i=2; i<=n; i++) {
        int minusOne = dp[i-1];
        int divideByTwo = INT_MAX, divideByThree = INT_MAX;

        if(i % 2 == 0)
            divideByTwo = dp[i / 2];

        if(i % 3 == 0)
            divideByThree = dp[i / 3];

        dp[i] = 1 + min(minusOne, min(divideByTwo, divideByThree));
    }
    return dp[n];
}

int main() {

	int n = 10;

	cout << minSteps(n) << endl;

	vector<int> dp(n + 1, -1); // 0th index of dp[] is not used

	cout << minStepsTopDown(n, dp) << endl;

	cout << minStepsBottomUp(n) << endl;

	return 0;
}