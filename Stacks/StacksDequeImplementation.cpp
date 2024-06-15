#include<iostream>
#include<deque>
using namespace std;

class Stack {
    deque<int> deq;

    public:
        void push(int val) {
            deq.push_front(val);
        }
        
        void pop() {
            if (deq.empty()) {
                cout << "Stack Underflow!";
                return;
            }
            deq.pop_front();
        }

        int top() {
            return deq.front();
        }

        int size() {
            return deq.size();
        }

        bool empty() {
            return deq.empty();
        }
};

int main() {
    
    Stack s;

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	return 0;
}