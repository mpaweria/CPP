#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
class graph {

	unordered_map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {
		// add a directed edge between vertex 'u' and 'v'
		neighbourMap[u].push_back(v);
	}

    void dfsHelper(T src, unordered_set<T>& visited, vector<T>& ordering) {
        visited.insert(src);

        list<T> neighbourList = neighbourMap[src];

        for(T neighbour: neighbourList) {
            if(visited.find(neighbour) == visited.end())
                dfsHelper(neighbour, visited, ordering);
        }
        ordering.push_back(src);
    }

    void topologicalSort() {
        unordered_map<T, int> inDegMap;

        for(pair<T, list<T>> p: neighbourMap) {
            list<T> neighbourList = p.second;
            for(T neighbour: neighbourList)
                inDegMap[neighbour]++;
        }

        unordered_set<T> visited;
        vector<T> ordering;

        for(pair<T, list<T>> p: neighbourMap) {
            T vertexLabel = p.first;
            if(inDegMap.find(vertexLabel) == inDegMap.end()) {
                dfsHelper(vertexLabel, visited, ordering);
            }
        }

        reverse(ordering.begin(), ordering.end());

        for(int i=0; i<ordering.size(); i++)
            cout << ordering[i] << " ";
    }
};

int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('A', 'D');
	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('D', 'C');
	g.addEdge('D', 'E');
	g.addEdge('D', 'F');
	g.addEdge('D', 'G');
	g.addEdge('D', 'H');
	g.addEdge('E', 'G');
	g.addEdge('F', 'C');
	g.addEdge('G', 'H');
	g.addEdge('H', 'F');

	g.topologicalSort();

	return 0;
}