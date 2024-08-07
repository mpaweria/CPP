#include<iostream>
#include<unordered_map>
using namespace std;

class pairHash {
    public: 

        size_t operator()(pair<string, int> p) const {
            return hash<string>()(p.first) ^ hash<int>()(p.second); 
            // return hash<string>{}(p.first) ^ hash<int>{}(p.second);   {} can also be used
        }
};

int main() {

	// this time, we will represent a customer using a pair<string, int>

	unordered_map<pair<string, int>, double, pairHash> ratingMap;

	ratingMap[ {"Yash", 19}] = 4.5;
	ratingMap[ {"Aryan", 18}] = 3.7;
	ratingMap[ {"Chirag", 20}] = 2.8;
    
	ratingMap[ {"Chirag", 20}] = 3.8;

	for (pair<pair<string, int>, double> p : ratingMap) {
		pair<string, int> c = p.first;
		double rating = p.second;
		cout << c.first << " " << c.second << " = " << rating << endl;
	}

	cout << endl;

	return 0;
}