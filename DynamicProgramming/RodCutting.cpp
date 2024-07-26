/*



Given a rod of length 'n' along with prices of its pieces of different lengths, design an algorithm to
compute the maximum profit we can make by cutting the rod and a selling its pieces.

Example :

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [1,  5,  8,  9,  10, 17, 17, 20]
	Output : 22

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [3,  5,  8,  9, 10, 17, 17, 20]
	Output : 24


*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxProfit(vector<int> p, int n) {
    // base case
    if(n == 0)
        return 0;

    // recursive case
    int maxSoFar = 0;
    for(int i=0; i<n; i++){
        maxSoFar = max(maxSoFar, p[i] + maxProfit(p, n-(i+1)));
    }
    return maxSoFar;
}

int maxProfitTopDown(vector<int> p, int n, vector<int> &dp) {
    if(dp[n] != -1)
        return dp[n];

    // base case
    if(n == 0)
        return dp[n] = 0;

    // recursive case
    int maxSoFar = 0;
    for(int i=0; i<n; i++){
        maxSoFar = max(maxSoFar, p[i] + maxProfitTopDown(p, n-(i+1), dp));
    }
    return dp[n] = maxSoFar;
}

int maxProfitBottomUp(vector<int> p, int n) {
    vector<int> dp(n+1, 0);
    
    for(int i=1; i<=n; i++) {
        int maxSoFar = 0;
        for(int j=0; j<i; j++){
            maxSoFar = max(maxSoFar, p[j] + dp[i-(j+1)]);
        }
        dp[i] = maxSoFar;
    }
    return dp[n];
}

int main() {

	vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20};
	// vector<int> p = {3,  5,  8,  9, 10, 17, 17, 20};
	int n = p.size();

    cout << maxProfit(p, n) << endl;

    vector<int> dp(n+1, -1);
    cout << maxProfitTopDown(p, n, dp) << endl;

    cout << maxProfitBottomUp(p, n) << endl;

    return 0;
}