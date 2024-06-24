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
            arr = new T[n+1];
            f = 0;
            r = 0;
            count = 0;
            this->n = n+1;
        }

        void push(T val) {
            if((r+1)%n == f) {
                cout << "Queue Overflow!";
                return;
            }
            r = (r+1)%n;
            arr[r] = val;
            count++;
        }

        void pop() {
            if(f == r) {
                cout << "Queue Underflow!";
                return;
            }
            f = (f+1)%n;
            count--;
        }

        int front() {
            return arr[(f+1)%n];
        }

        bool empty() {
            return f == r;
        }

        int size() {
            return count;
        }

        void print() {
            for(int i = (f+1) % n; i != (r+1) % n; i = (i+1) % n)
                cout << arr[i] << " ";
            cout << endl;
        }
};
int main() {

	Queue<int> q(5);

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	q.print(); // 10 20 30 40 50

	q.pop();

	q.print(); // 20 30 40 50

	q.push(60);

	q.print(); // 20 30 40 50 60

	q.pop();

	q.push(70);

	q.print(); // 30 40 50 60 70

	return 0;
}