#include<iostream>
#include<list>
using namespace std;

class Stack {
    list<int> dll;

    public:
        void push(int val) {
            dll.push_back(val);
        }
        
        void pop() {
            if (dll.empty()) {
                cout << "Stack Underflow!";
                return;
            }
            dll.pop_back();
        }

        int top() {
            return dll.back();
        }

        int size() {
            return dll.size();
        }

        bool empty() {
            return dll.empty();
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