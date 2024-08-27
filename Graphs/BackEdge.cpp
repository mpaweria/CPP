#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>

using namespace std;

template <typename T>
class graph {

	unordered_map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {
		// add a directed edge between vertex 'u' and 'v'
		neighbourMap[u].push_back(v);
	}

    bool dfsHelper(T source, unordered_set<T> &visited, unordered_set<T> &stackState) {
        visited.insert(source);
        stackState.insert(source);

        list<T> neighbourList = neighbourMap[source];

        for(T neighbour: neighbourList) {
            if(visited.find(neighbour) == visited.end()) {
                if(dfsHelper(neighbour, visited, stackState))
                    return true;
            } else {
                if(stackState.find(neighbour) != stackState.end())
                    return true;
            }
        }
        stackState.erase(source);
        return false;
    }

    bool isBackEdgePresent() {
        unordered_set<T> visited;
        unordered_set<T> stackState;
        bool flag = false;

        for(auto p: neighbourMap) {
            T vertexLabel = p.first;
            if(visited.find(vertexLabel) == visited.end()) {
                if(dfsHelper(vertexLabel, visited, stackState)) {
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
	g.addEdge('B', 'C');
	g.addEdge('C', 'D');
	// g.addEdge('D', 'A');

	g.isBackEdgePresent() ? cout << "back-edge found!" << endl :
	                             cout << "back-edge not found!" << endl;

	return 0;
}