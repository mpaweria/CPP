    #include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents
	unordered_map<T, int> rankMap;   // to store a mapping b/w vertices & their ranks i.e. sizes

public :

	void createSet(T x) {
		parentMap[x] = x;
		rankMap[x] = 1;
	}

	T findSet(T x) {
		if (parentMap[x] == x) {
			return x;
		}

		return parentMap[x] = findSet(parentMap[x]); // path compression
	}

	void unionSet(T x, T y) {
		T l_x = findSet(x);
		T l_y = findSet(y);
		if (l_x != l_y) {
			if (rankMap[l_x] > rankMap[l_y]) { // union by rank (size)
				parentMap[l_y] = l_x;
				rankMap[l_x] += rankMap[l_y];
			} else {
				parentMap[l_x] = l_y;
				rankMap[l_y] += rankMap[l_x];
			}
		}
	}

};


template <typename T>
class edge {
public :

	T u;
	T v;
	int w;

	edge(T u, T v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

// return true if you want e1 to be ordered before e2 otherwise return false

template <typename T>
bool edgeComparator(edge<T> e1, edge<T> e2) {

	// if(e1.w < e2.w) {
	// 	// you want e1 to be ordered before e2 since we are sorting in inc. order
	// 	return true;
	// }

	// return false;

	return e1.w < e2.w;
}

template <typename T>
class graph {

	set<T>  vertexSet;        // to store the graph representation
	vector<edge<T>> edgeList; // to store the graph representation

public :

	void addEdge(T u, T v, int w) {
		// add an edge of weight 'w' b/w 'u' and 'v'
		edgeList.push_back(edge<T>(u, v, w));
		vertexSet.insert(u);
		vertexSet.insert(v);
	}

    vector<edge<T>> kruskal() {
        disjointSet<T> ds;
        for(T vertex: vertexSet)
            ds.createSet(vertex);

        sort(edgeList.begin(), edgeList.end(), edgeComparator<T>);

        vector<edge<T>> MST;
        int minSum = 0;
        for(edge<T> e: edgeList) {
            if(ds.findSet(e.u) != ds.findSet(e.v)) {
                ds.unionSet(e.u, e.v);
                minSum += e.w;
                MST.push_back(e);

                if(MST.size() == vertexSet.size()-1)
                    break;
            }
        }
        cout << minSum << endl;
        
        return MST;
    }
};

int main() {

	graph<char> g;

	g.addEdge('A', 'B', 4);
	g.addEdge('A', 'C', 5);
	g.addEdge('B', 'D', 2);
	g.addEdge('B', 'E', 7);
	g.addEdge('C', 'D', 6);
	g.addEdge('C', 'F', 9);
	g.addEdge('E', 'F', 1);
	g.addEdge('E', 'G', 3);
	g.addEdge('F', 'G', 8);

	vector<edge<char>> mst = g.kruskal();

	for (edge<char> e : mst) {
		cout << "(" << e.u << ", " << e.v << ", " << e.w << ")" << endl;
	}

	return 0;
}