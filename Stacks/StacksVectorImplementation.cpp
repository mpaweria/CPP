#include<iostream>
#include<vector>
using namespace std;

class Stack {
    vector<int> vec;

    public:
        void push(int val) {
            vec.push_back(val);
        }
        
        void pop() {
            if (vec.empty()) {
                cout << "Stack Underflow!";
                return;
            }
            vec.pop_back();
        }

        int top() {
            return vec.back();
        }

        int size() {
            return vec.size();
        }

        bool empty() {
            return vec.empty();
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