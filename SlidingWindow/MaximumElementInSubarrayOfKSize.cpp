#include<iostream>
#include<vector>
#include<deque>
#include<climits>
using namespace std;

int main() {
    vector<int> vec = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k = 4;

    deque<int> deq;
    vector<int> v;

    for(int i=0; i<vec.size(); i++) {
        if(!deq.empty() && deq.front() == i-k)
            deq.pop_front();

        while (!deq.empty() && vec[deq.back()] <= vec[i])
        {
            deq.pop_back();
        }
        deq.push_back(i);

        if(i >= k-1)
            v.push_back(vec[deq.front()]);
    }

    for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

    return 0;
}