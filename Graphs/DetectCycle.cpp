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

    bool dfsHelper(T source, unordered_set<T> &visited, T parent) {
        visited.insert(source);

        list<T> neighbourList = neighbourMap[source];

        for(T neighbour: neighbourList) {
            if(visited.find(neighbour) == visited.end()) {
                if(dfsHelper(neighbour, visited, source))
                    return true;
            } else {
                if(neighbour != parent)
                    return true;
            }
        }
        return false;
    }

    bool isCyclePresent() {
        unordered_set<T> visited;

        bool flag = false;
        for(auto p: neighbourMap) {
            T vertexLabel = p.first;
            if(visited.find(vertexLabel) == visited.end()) {
                if(dfsHelper(vertexLabel, visited, vertexLabel)) {
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
};

int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'C');

	g.isCyclePresent() ? cout << "cycle found!" << endl :
	                          cout << "cycle not found!" << endl;

	return 0;
}