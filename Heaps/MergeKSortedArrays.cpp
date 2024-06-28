#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class triple {

public :

    int val;
    int row;
    int col;

    triple(int val, int row, int col) {
        this->val = val;
        this->row = row;
        this->col = col;
    }

};

class TripleComparator {
    public:
        bool operator()(triple a, triple b) {
            return a.val > b.val;
        }
};

int main() {

    vector<vector<int>> inp = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    int k = inp.size();

    priority_queue<triple, vector<triple>, TripleComparator> minHeap;

    for(int i=0; i<k; i++){
        minHeap.push(triple(inp[i][0], i, 0));
    }

    vector<int> out;

    while (!minHeap.empty())
    {
        triple minTriple = minHeap.top();
        minHeap.pop();
        out.push_back(minTriple.val);

        int col = minTriple.col, row = minTriple.row;

        if(col + 1 < inp[row].size()){
            minHeap.push(triple(inp[row][col+1], row, col+1));
        }
    }
    
    for(int i: out)
        cout << i << " ";

    return 0;
}