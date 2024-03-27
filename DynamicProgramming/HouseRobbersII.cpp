#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> nums, int i, int n){
    // base case
    if(i >= n)
        return 0;

    // recursive case
    return max((nums[i] + maxProfit(nums, i+2, n)), maxProfit(nums, i+1, n));
}

int maxProfitTopDown(vector<int> nums, int i, int n, vector<int>& dp) {
    // look up
    if(dp[i] != -1)
        return dp[i];

    // base case
    if(i >= n)
        return dp[i] = 0;

    // recursive case
    return dp[i] = max((nums[i] + maxProfitTopDown(nums, i+2, n, dp)), maxProfitTopDown(nums, i+1, n, dp));
}

int maxProfitBottomUp(vector<int> nums, int i, int n) {
    vector<int> dp(n+2);
    dp[n+1] = dp[n] = 0;

    for(int i=n-1; i>=0; i--) {
        dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
    }
    return dp[0];
}

int rob(vector<int> house) {
    int n = house.size();
    if(n==0)
        return 0;
    if(n==1)
        return house[0];

    vector<int> dp(n+2, -1);

    // int skipLastHouse = maxProfit(house, 0, n-1);
    // int skipFirstHouse = maxProfit(house, 1, n);

    int skipLastHouse = maxProfitTopDown(house, 0, n-1, dp);
    int skipFirstHouse = maxProfitTopDown(house, 1, n, dp);

    // int skipLastHouse = maxProfitBottomUp(house, 0, n-1);
    // int skipFirstHouse = maxProfitBottomUp(house, 1, n);

    return max(skipFirstHouse, skipLastHouse);
}

int main() {
    vector<int> house = {7, 4, 1, 9, 3, 8, 6, 5};

    cout << rob(house);

    return 0;
}