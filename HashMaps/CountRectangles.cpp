#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	bool operator==(Point p) const {
        return this->x == p.x && this->y == p.y;
    }
};

class PointHash {
    public:

        size_t operator()(Point p) const {
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }
};

int countRectangles(vector<Point> points, int n) {
    unordered_set<Point, PointHash> s(points.begin(), points.end());

    int totalRectangles = 0;

    for(int i=0; i <= n-2; i++) {
        Point p1 = points[i];

        for(int j=i+1; j <= n-1; j++) {
            Point p2 = points[j];

            if(p1.x != p2.x && p1.y != p2.y) {
                Point p3 = Point(p2.x, p1.y);
                Point p4 = Point(p1.x, p2.y);

                if(s.find(p3) != s.end() && s.find(p4) != s.end())
                    totalRectangles++;
            }
        }
    }

    return totalRectangles / 2;
}

int main() {

	vector<Point> points{
		Point(1, 1),
		Point(1, 2),
		Point(2, 1),
		Point(2, 2),
		Point(3, 1),
		Point(3, 2)
	};

    int n = points.size();

    cout << countRectangles(points, n);

    return 0;
}