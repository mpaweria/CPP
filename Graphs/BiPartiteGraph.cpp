#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class graph {

	unordered_map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {

		// adds an edge b/w vertex u and v

		neighbourMap[u].push_back(v);
		neighbourMap[v].push_back(u);

	}

    bool bfsHelper(T source, unordered_map<T, int> colorMap) {
        queue<T> q;

        q.push(source);
        colorMap[source] = 0;

        while(!q.empty()) {
            T front = q.front();
            q.pop();

            list<T> neighbourList = neighbourMap[front];

            for(auto neighbour : neighbourList) {
                if(colorMap.find(neighbour) == colorMap.end()) {
                    colorMap[neighbour] = !colorMap[front];
                    q.push(neighbour);
                } else {
                    if(colorMap[neighbour] == colorMap[front])
                        return false;
                }
            }
        }
        return true;
    }

    bool isBiPartite() {
        bool flag = true;
        unordered_map<T, int> colorMap;
        
        for(auto p: neighbourMap) {
            T vertexLabel = p.first;
            if(colorMap.find(vertexLabel) == colorMap.end()) {
                if(!bfsHelper(vertexLabel, colorMap)) {
                    flag = false;
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
	g.addEdge('B', 'D');
	g.addEdge('C', 'E');

	g.isBiPartite() ? cout << "bipartite!" << endl : cout << "not bipartite!" << endl;

	return 0;
}