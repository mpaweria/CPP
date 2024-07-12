#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestConsecutive(vector<int> &nums) {
    unordered_map<int, bool> map;

    for(int num: nums) {
        if(map.find(num-1) == map.end()) {
            map[num] = true;
        } else {
            map[num] = false;
        }

        if(map.find(num+1) != map.end())
            map[num+1] = false;
    }

    int maxSoFar = 0;
    for(pair<int, bool> p: map) {
        if(p.second == true) {
            int count = 0, key = p.first;

            while (map.find(key) != map.end())
            {
                count++;
                key++;
            }
            maxSoFar = max(maxSoFar, count);
        }
    }
    return maxSoFar;
}

int main() {
	vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 11, 12, 13, 14};

	cout << longestConsecutive(nums) << endl;

}