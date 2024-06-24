#include<iostream>
#include<deque>
using namespace std;

template <typename T>
class Queue {
    deque<T> dq;

    public: 
        void push(T val) {
            dq.push_back(val);
        }

        void pop() {
            dq.pop_front();
        }

        T front() {
            return dq.front();
        }

        int size() {
            return dq.size();
        }

        bool empty() {
            return dq.empty();
        }
};

int main() {

	Queue<int> q;

	cout << "size : " << q.size() << endl;
	q.empty() ? cout << "Queue is empty!" << endl :
	                 cout << "Queue is not empty!" << endl;

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();
	q.empty() ? cout << "Queue is empty!" << endl :
	                 cout << "Queue is not empty!" << endl;


	return 0;
}