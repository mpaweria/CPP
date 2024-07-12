#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Point {
    public:
        int x;
        int y;

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

int countTriangles(vector<Point> points) {
    unordered_map<int, int> xFreqMap, yFreqMap;

    for(Point p: points) {
        xFreqMap[p.x]++;
        yFreqMap[p.y]++;
    }

    int totalTriangles = 0;
    for(Point p: points) {
        int xCount = xFreqMap[p.x], yCount = yFreqMap[p.y];

        totalTriangles += (xCount - 1) * (yCount - 1);
    }

    return totalTriangles;
}

int main() {
    vector<Point> points = {
		Point(1, 2),
		Point(2, 0),
		Point(2, 2),
		Point(2, 3),
		Point(4, 2)
	};

    cout << countTriangles(points);

    return 0;
}