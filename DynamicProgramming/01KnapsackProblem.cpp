#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> weights, vector<int> profits, int N, int W, int i) {
    // base case
    if(i == N)
        return 0;

    if(W == 0)
        return 0;

    // recursive case
    if(weights[i] > W)
        return maxProfit(weights, profits, N, W, i+1);

    return max(profits[i] + maxProfit(weights, profits, N, W-weights[i], i+1), maxProfit(weights, profits, N, W, i+1));
}

int main() {
	int N = 5;
	int W = 4;

	vector<int> weights = {1, 2, 3, 2, 2};
	vector<int> profits = {8, 4, 1, 5, 3};

    cout << maxProfit(weights, profits, N, W, 0);

    return 0;
}