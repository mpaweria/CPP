#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<algorithm>
#include<queue>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {
		// insert a directed edge between vertex 'u' and 'v'
		neighbourMap[u].push_back(v);
	}

	void print() {
		for (pair<T, list<T>> vertex : neighbourMap) {
			T vertexLabel = vertex.first;
			list<T> neighbourList = vertex.second;
			cout << vertexLabel << " : ";
			for (T neighbour : neighbourList) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

    int bfs(T src, T dest) {
        map<T, int> distMap;
        distMap[src] = 0;

        map<T, T> parentMap;
        parentMap[src] = src;

        unordered_set<T> visited;
        queue<T> q;

        visited.insert(src);
        q.push(src);

        while(!q.empty()) {
            T front = q.front();
            q.pop();

            visited.insert(front);

            list<T> neighbourList = neighbourMap[front];

            for(T neighbour : neighbourList) {
                if(visited.find(neighbour) == visited.end()) {
                    visited.insert(neighbour);
                    q.push(neighbour);

                    distMap[neighbour] = distMap[front] + 1;
                    parentMap[neighbour] = front;
                }
            }
        }

        vector<T> shortestPath;
        T temp = dest;

        while(parentMap[temp] != temp) {
            shortestPath.push_back(temp);
            temp = parentMap[temp];
        }
        shortestPath.push_back(src);

        reverse(shortestPath.begin(), shortestPath.end());

        for(T p: shortestPath) 
            cout << p << " ";
        cout << endl;
        
        return distMap[dest];
    }
};

int minDiceThrows(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders) {
    int weightMap[n+1] = {0};

    for(pair<int, int> ladderPos: ladders) {
        int startPos = ladderPos.first;
        int endPos = ladderPos.second;
        weightMap[startPos] = startPos - endPos;
    }

    for(pair<int, int> snakePos: snakes) {
        int startPos = snakePos.first;
        int endPos = snakePos.second;
        weightMap[startPos] = startPos - endPos;
    }

    graph<int> g;

    for(int u = 1; u < n; u++) {
        if(weightMap[u] != 0)
            continue;
        for(int d = 1; d <= 6; d++) {
            int v = u + d;
            if(v <= n) {
                v = v + weightMap[v];
                g.addEdge(u, v);
            }
        }
    }
    return g.bfs(1, n);
}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {
		{17, 4},
		{20, 6},
		{24, 16},
		{32, 30},
		{34, 12}
	};

	vector<pair<int, int>> ladders = {
		{2, 15},
		{5, 7},
		{9, 27},
		{18, 29},
		{25, 35}
	};

	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}