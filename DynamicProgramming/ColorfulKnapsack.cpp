#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<climits>
using namespace std;

int minWeight( vector<int> weights, unordered_map<int, vector<int>> colorMap, int n, int m, int i, int w) {
    // base case
    if(i == m+1)
        return w;
    
    if(w == 0)
        return INT_MAX;

    // recursive case
    int totalWeight = INT_MAX;
    vector<int> colors = colorMap[i];

    for(int color: colors) {
        if(color <= w) {
            totalWeight = min(totalWeight, minWeight(weights, colorMap, n, m, i+1, w - color));
        }
    }
    return totalWeight;
}

int minWeightTopDown( vector<int> weights, unordered_map<int, vector<int>> colorMap, int n, int m, int i, int w, map<pair<int, int>, int> dp) {
    // look up
    pair<int, int> key = make_pair(i, w);

    if(dp.find(key) != dp.end())
        return dp[key];

    // base case
    if(i == m+1)
        return dp[key] = w;
    
    if(w == 0)
        return dp[key] = INT_MAX;

    // recursive case
    int totalWeight = INT_MAX;
    vector<int> colors = colorMap[i];

    for(int color: colors) {
        if(color <= w) {
            totalWeight = min(totalWeight, minWeightTopDown(weights, colorMap, n, m, i+1, w - color, dp));
        }
    }
    return dp[key] = totalWeight;
}

int main() {
    int n = 8;
	int w = 13;
    int m = 3;
	vector<int> weights = {2, 3, 4, 2, 4, 5, 2, 3};
	vector<int> colors = {1, 1, 1, 2, 2, 2, 3, 3};

    unordered_map<int, vector<int>> colorMap;

    for(int i=0; i<n; i++) {
        colorMap[colors[i]].push_back(weights[i]);
    }

    cout << minWeight(weights, colorMap, n, m, 1, w) << endl;

    map<pair<int, int>, int> dp;

    cout << minWeightTopDown(weights, colorMap, n, m, 1, w, dp) << endl;
}