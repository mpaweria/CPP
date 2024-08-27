#include<iostream>
#include<list>
using namespace std;

class graph {
    int V;
    bool isDirected;
    list<int> *arr;

    public:
        graph(int V, bool isDirected = false) {
            this->V = V;
            this->isDirected = isDirected;
            arr = new list<int>[V];
        }

        void addEdge(int u, int v) {
            arr[u].push_back(v);
            
            if(!isDirected)
                arr[v].push_back(u);
        }

        void print() {
            for(int i=0; i<V; i++) {
                list<int> neighbours = arr[i];
                cout << i << " : ";
                for(int ngbr: neighbours)
                    cout << ngbr << " ";
                cout << endl;
            }
        }

};

int main() {

	graph g(5);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);

	g.print();

	return 0;
}