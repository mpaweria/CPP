/*
    https://leetcode.com/problems/course-schedule-ii/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class Graph {
public :

    unordered_map<T, list<T>> neighbourMap;

    Graph(int V) {
        // courses you have to take are labeled from 0 to V-1
        for (int i = 0; i < V; i++) {
            neighbourMap[i] = {}; // or use list<int>() instead of {}
        }
    }

    void addEdge(T u, T v) {
        // adds a directed edge from u i.e. b_i to v i.e. a_i
        neighbourMap[u].push_back(v);
    }

    void printGraph() {
        for (pair<T, list<T>> vertex : neighbourMap) {
            T vertexName = vertex.first;
            list<T> neighbourList = vertex.second;
            cout << vertexName << " : ";
            for (T neighbour : neighbourList) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    vector<int> topologicalSort() {
        unordered_map<T, int> inDegreeMap;
        vector<int> couresOrder;

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

            couresOrder.push_back(front);

            list<T> neighbourList = neighbourMap[front];
            for(T neighbour : neighbourList) {
                inDegreeMap[neighbour]--;
                if(inDegreeMap[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        return couresOrder;
    }
};

int main() {
    int numCourses = 4;
    Graph<int> g(numCourses);
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    for (int i = 0; i < prerequisites.size(); i++) {
        int a_i = prerequisites[i][0];
        int b_i = prerequisites[i][1];
        g.addEdge(b_i, a_i);
    }

    // g.printGraph();

    vector<int> courseOrder = g.topologicalSort();

    courseOrder.size() == numCourses ? courseOrder : courseOrder = {};
    for (int vertex : courseOrder) {
        cout << vertex << " ";
    }

    return 0;
}