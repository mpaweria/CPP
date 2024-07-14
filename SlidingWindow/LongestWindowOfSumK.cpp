#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> vec = {2, 3, 2, 4, 0, 2, 0};
    int k = 6;

    int i = 0, j = 0, wSum = 0, maxLength = 0;

    while (j < vec.size())
    {
        wSum += vec[j];

        while (wSum > k)
        {
            wSum -= vec[i];
            i++;
        }
        
        if(wSum == k) {
            maxLength = max(maxLength, j-i+1);
        }

        j++;
    }
    
    cout << maxLength;

    return 0;
}