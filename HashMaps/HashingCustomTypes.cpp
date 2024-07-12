#include<iostream>
#include<unordered_map>
using namespace std;

class customer {
    public:
        string name;
        int age;

        customer(string name, int age) {
            this->name = name;
            this->age = age;
        }

        bool operator==(customer c) const {
            return this->name == c.name && this->age == c.age;
        }
};

class customerHash {
    public:

        size_t operator()(customer c) const {
            hash<string> stringHash;
            size_t nameHash = stringHash(c.name);

            hash<int> intHash;
            size_t ageHash = intHash(c.age);

            return nameHash ^ ageHash;
        }
};

int main() {

	unordered_map<customer, double, customerHash> ratingMap;

	ratingMap[customer("Yash", 19)] = 4.5;
	ratingMap[customer("Aryan", 18)] = 3.7;
	ratingMap[customer("Chirag", 20)] = 2.8;

	for (pair<customer, double> p : ratingMap) {
		customer c = p.first;
		double rating = p.second;
		cout << "customer(" << c.name << ", " << c.age << ") = " << rating << endl;
	}

	cout << endl;

	ratingMap[customer("Aryan", 18)] = 4.7;


	for (pair<customer, double> p : ratingMap) {
		customer c = p.first;
		double rating = p.second;
		cout << "customer(" << c.name << ", " << c.age << ") = " << rating << endl;
	}


	return 0;
}