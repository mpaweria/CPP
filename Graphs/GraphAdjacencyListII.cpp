#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class graph {
    unordered_map<T, list<T>> neighbourMap;
    bool isDirected;

    public:
        graph(bool isDirected = false) {
            this->isDirected = isDirected;
        }

        void addEdge(T u, T v) {
            neighbourMap[u].push_back(v);

            if(!isDirected)
                neighbourMap[v].push_back(u);
        }

        void print() {
            for(pair<T, list<T>> p: neighbourMap) {
                T label = p.first;
                list<T> neighbourList = p.second;
                cout << label << " : ";
                for(int ngbr: neighbourList)
                    cout << ngbr << " ";
                cout << endl;
            }
        }
};

int main() {

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);

	g.print();

	return 0;
}