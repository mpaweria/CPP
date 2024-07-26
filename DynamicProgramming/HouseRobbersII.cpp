#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> houses, int index, int lastIndex) {
    // base case
    if(index > lastIndex)
        return 0;

    // recursive case
    int rob = houses[index] + helper(houses, index+2, lastIndex);
    int doNotRob = helper(houses, index+1, lastIndex);

    return max(rob, doNotRob);
}

int helperTopDown(vector<int> houses, int index, int lastIndex, vector<int>& dp) {
    // look up
    if(dp[index] != -1)
        return dp[index];

    // base case
    if(index > lastIndex)
        return dp[index] = 0;

    // recursive case
    int rob = houses[index] + helperTopDown(houses, index+2, lastIndex, dp);
    int doNotRob = helperTopDown(houses, index+1, lastIndex, dp);

    return dp[index] = max(rob, doNotRob);
}

int helperBottomUp(vector<int> nums) {
    int n = nums.size();
        if (n == 1) return nums[0];
        

        vector<int> dp2(n);

        
        dp2[n-1] = nums[n-1];
        dp2[n-2] = max(nums[n-1],nums[n-2]);

        for(int i= n - 3 ;i>=0;i--){
            if(i==0){
                dp2[0] = max( dp2[1] , dp2[2]) ;
            }
            else{
                dp2[i] = max(dp2[i+1], dp2[i+2] + nums[i]);
            }
        }
        

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            if(i==n-1 ){
                dp[i] = max(dp[i-1] , dp[n-2]) ;
            }
            else
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
       return  max(dp2[0] ,  dp[n-1]);

}

int rob(vector<int> houses) {
    int n = houses.size();

    // int first = helper(houses, 0, n-2);
    // int second = helper(houses, 1, n-1);

    // vector<int> dp(n+1, -1);
    // int first = helperTopDown(houses, 0, n-2, dp);
    // int second = helperTopDown(houses, 1, n-1, dp);

    // return max(first, second);

    return helperBottomUp(houses);
}

int main() {
    vector<int> houses = {1,2,3,1};

    cout << rob(houses);

    return 0;
}