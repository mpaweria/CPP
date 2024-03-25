#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> nums, int i){
    // base case
    if(i >= nums.size())
        return 0;

    // recursive case
    return max((nums[i] + maxProfit(nums, i+2)), maxProfit(nums, i+1));
}

int maxProfitTopDown(vector<int> nums, int i, vector<int>& dp) {
    // look up
    if(dp[i] != -1)
        return dp[i];
    
    // base case
    if(i >= nums.size())
        return 0;

    // recursive case
    return dp[i] = max((nums[i] + maxProfit(nums, i+2)), maxProfit(nums, i+1));
}

int maxProfitBottomUp(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n+2);
    dp[n+1] = dp[n] = 0;

    for(int i=nums.size()-1; i>=0; i--){
        dp[i] = max((nums[i] + dp[i+2]), dp[i+1]);
    }
    return dp[0];
}

int main() {
    vector<int> nums = {100, 50, 400, 200, 100};
    vector<int> dp(nums.size()+1, -1);

    cout << maxProfit(nums, 0) << endl;
    cout << maxProfitTopDown(nums, 0, dp) << endl;
    cout << maxProfitBottomUp(nums) << endl;

    return 0;
}