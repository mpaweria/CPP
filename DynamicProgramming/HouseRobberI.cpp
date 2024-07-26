#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int> nums, int n, int i) {
    // base case
    if(i >= n)
        return 0;

    // recursive case
    int robHouse = nums[i] + helper(nums, n, i+2);
    int doNotRobHouse = helper(nums, n, i+1);

    return max(robHouse, doNotRobHouse);
}

int helperTopDown(vector<int> nums, int n, int i, vector<int> &dp) {
    // lookup
    if(dp[i] != -1)
        return dp[i];

    // base case
    if(i >= n)
        return dp[i] = 0;

    // recursive case
    int robHouse = nums[i] + helperTopDown(nums, n, i+2, dp);
    int doNotRobHouse = helperTopDown(nums, n, i+1, dp);

    return dp[i] = max(robHouse, doNotRobHouse);
}

int helperBottomUp(vector<int> nums, int n) {
    vector<int> dp(n+1);
    dp[n] = 0;
    dp[n-1] = nums[n-1];

    for(int i=n-2; i>=0; i--) {
        dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
    }
    return dp[0];
}

int rob(vector<int> nums) {
    int n = nums.size();

    // return helper(nums, n , 0);

    vector<int> dp(n+1, -1);
    // return helperTopDown(nums, n, 0, dp);

    return helperBottomUp(nums, n);
}

int main() {

    vector<int> nums = {100, 50, 400, 200, 100};

    cout << rob(nums) << endl;

    return 0;
}