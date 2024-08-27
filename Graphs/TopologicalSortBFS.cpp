#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class graph {

	unordered_map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {
		// add a directed edge between vertex 'u' and 'v'
		neighbourMap[u].push_back(v);
	}

    void topologicalSort() {
        unordered_map<T, int> inDegreeMap;

        for(auto p: neighbourMap) {
            list<T> neighbourList = p.second;
            for(T neighbour : neighbourList)
                inDegreeMap[neighbour]++;
        }

        queue<T> q;

        for(auto p: neighbourMap) {
            T vertexLabel = p.first;
            if(inDegreeMap.find(vertexLabel) == inDegreeMap.end())
                q.push(vertexLabel);
        }

        while(!q.empty()) {
            T front = q.front();
            q.pop();

            cout << front << " ";

            list<T> neighbourList = neighbourMap[front];
            for(T neighbour : neighbourList) {
                inDegreeMap[neighbour]--;
                if(inDegreeMap[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        cout << endl;
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