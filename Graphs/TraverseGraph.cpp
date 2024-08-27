#include<iostream>
#include<unordered_map>
#include<list>
#include<unordered_set>

using namespace std;

template <typename T>
class graph {

	unordered_map<T, list<T>> neighbourMap; // to store the graph representation
	bool isDirected; // to indicate if the graph is directed or not

public :

	graph(bool isDirected = false) {
		this->isDirected = isDirected;
	}

	void addEdge(T u, T v) {

		// adds an edge b/w vertex u and v

		neighbourMap[u].push_back(v);

		if (!isDirected) {
			neighbourMap[v].push_back(u);
		}

	}

    void dfsHelper(T source, unordered_set<T> &visited) {
        visited.insert(source);
        cout << source << " ";

        list<T> neighbourList = neighbourMap[source];

        for(T neighbour: neighbourList) {
            if(visited.find(neighbour) == visited.end()) {
                dfsHelper(neighbour, visited);
            }
        }
    }

    void traverse() {
        unordered_set<T> visited;
        int numComponents = 0;

        for(auto p: neighbourMap) {
            T vertexLabel = p.first;
            if(visited.find(vertexLabel) == visited.end()) {
                cout << "dfs(" << vertexLabel << ") : ";
                dfsHelper(vertexLabel, visited);
                numComponents++;
                cout << endl;
            }
        }

        cout << "Number of components: " << numComponents;
    }
};

int main() {

	graph<char> g;

	g.addEdge('A', 'C');
	g.addEdge('A', 'D');
	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('C', 'F');
	g.addEdge('D', 'F');
	g.addEdge('D', 'G');
	g.addEdge('E', 'G');

	g.addEdge('H', 'J');
	g.addEdge('I', 'J');
	g.addEdge('J', 'K');
	g.addEdge('J', 'L');

	g.addEdge('M', 'N');
	g.addEdge('M', 'O');
	g.addEdge('N', 'P');
	g.addEdge('O', 'P');

	g.traverse();

	return 0;
}