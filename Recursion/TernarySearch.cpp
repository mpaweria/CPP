#include<iostream>
using namespace std;

int f(int x) {
	return -x * x + 100 * x; // -x^2 + 100x is a unimodal function
}

double findPeak(double s, double e) {
    // base case
    if(e - s <= 1e-6) {
        return f((s + e)/2);
    }

    // recursive case
    double m1 = s + (e - s) / 3;
    double m2 = e - (e - s) / 3;

    if(f(m1) < f(m2)) {
        return findPeak(m1, e);
    }
    return findPeak(s, m2);
}

int main() {
    double s = 0, e = 100;

    cout << findPeak(s, e) << endl;

    return 0;
}