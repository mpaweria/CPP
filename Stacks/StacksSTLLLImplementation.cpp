#include<iostream>
#include<forward_list>
using namespace std;

class Stack {
    forward_list<int> ll;

    public:
        void push(int val) {
            ll.push_front(val);
        }
        
        void pop() {
            if (ll.empty()) {
                cout << "Stack Underflow!";
                return;
            }
            ll.pop_front();
        }

        int top() {
            return ll.front();
        }

        int size() {
            return distance(ll.begin(), ll.end());
        }

        bool empty() {
            return ll.empty();
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