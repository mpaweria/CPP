#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class graph {
    unordered_map<T, list<pair<T, int>>> neighbourMap;
    bool isDirected;

    public:
        graph(bool isDirected = false) {
            this->isDirected = isDirected;
        }

        void addEdge(T u, T v, int w) {
            neighbourMap[u].push_back({v, w});

            if(!isDirected)
                neighbourMap[v].push_back({u, w});
        }

        void print() {
            for(pair<T, list<pair<T, int>>> p: neighbourMap) {
                T label = p.first;
                list<pair<T, int>> neighbourList = p.second;
                cout << label << " : ";
                for(pair<T, int> ngbr: neighbourList)
                    cout << "(" << ngbr.first << "," << ngbr.second << ") ";
                cout << endl;
            }
        }
};

int main() {

	graph<char> g;

	g.addEdge('A', 'B', 7);
	g.addEdge('A', 'C', 1);
	g.addEdge('B', 'D', 2);
	g.addEdge('C', 'D', 9);
	g.addEdge('C', 'E', 6);
	g.addEdge('D', 'E', 5);

	g.print();

	return 0;
	return 0;
}