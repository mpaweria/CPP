#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> vec = {1, 4, 2, 7, 6, 3, 5};
    int k = 4, i = 0, j = 0;

    int windowSum = 0;
    while (j < k)
    {
        windowSum += vec[j];
        j++;
    }
    
    int maxSum = windowSum;

    while (j < vec.size())
    {
        windowSum -= vec[i];
        i++;
        windowSum += vec[j];
        j++;

        maxSum = max(maxSum, windowSum);
    }
    cout << maxSum; 

    return 0;
}