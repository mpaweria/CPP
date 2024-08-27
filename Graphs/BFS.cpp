#include<iostream>
#include<unordered_map>
#include<list>
#include<unordered_set>
#include<queue>

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

    void bfs(T source) {
        unordered_set<T> visited;
        queue<T> q;

        visited.insert(source);
        q.push(source);

        while (!q.empty())
        {
            T front = q.front();
            q.pop();

            cout << front << " ";

            list<T> neighbourList = neighbourMap[front];
            
            for(T neighbour: neighbourList) {
                if(visited.find(neighbour) == visited.end()) {
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
        
    }
};

int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('C', 'E');
	g.addEdge('C', 'F');
	g.addEdge('D', 'G');
	g.addEdge('E', 'G');
	g.addEdge('E', 'H');
	g.addEdge('F', 'H');
	g.addEdge('G', 'I');
	g.addEdge('H', 'I');

	g.bfs('A');

	return 0;
}