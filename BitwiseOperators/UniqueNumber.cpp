#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {3, 1, 4, 1, 2, 3, 4};
    int ans = 0;
    for(int i=0; i<nums.size(); i++) {
        ans = ans ^ nums[i];
    }
    cout << "Unique number is: " << ans;

    return 0;
}