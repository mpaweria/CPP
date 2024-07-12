#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

int main() {
    vector<int> vec = {10, 10, 10, 20, 20, 30, 40, 50, 50, 60, 60, 60};
    int n = vec.size();
    int k = 3;

    unordered_map<int, int> map;

    for(int v: vec)
        map[v]++;

    priority_queue<pair<int, int>> pq;

    for(auto p: map) {
        pq.push({p.second, p.first});
    }

    while(k--) {
        pair<int, int> p = pq.top();
        pq.pop();
        cout << p.second << " ";
    }

    return 0;
}