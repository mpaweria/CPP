#include<iostream>
using namespace std;

template <typename T>
class Queue {
    T *arr;
    int n;
    int f;
    int r;
    int count;

    public:
        Queue(int n) {
            arr = new T[n];
            f = -1;
            r = -1;
            count = 0;
            this->n = n;
        }

        void push(T val) {
            if(r == n-1) {
                cout << "Queue Overflow!";
                return;
            }
            r++;
            arr[r] = val;
            count++;
        }

        void pop() {
            if(f == r) {
                cout << "Queue Underflow!";
                return;
            }
            f++;
            count--;
        }

        int front() {
            return arr[f+1];
        }

        bool empty() {
            return f == r;
        }

        int size() {
            return count;
        }
};

int main() {

	Queue<int> q(5);

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