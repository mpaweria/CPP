#include<iostream>
#include<stack>

using namespace std;

class customStack {
    stack<int> mainStack;
    stack<int> minStack;

    public:
        void push(int val) {
            if(minStack.empty() || minStack.top() >= val) {
                minStack.push(val);
            }
            mainStack.push(val);
        }
        
        void pop() {
            if (mainStack.empty()) {
                cout << "Stack Underflow!";
                return;
            }
            if(!minStack.empty() && mainStack.top() == minStack.top())
                minStack.pop();
            mainStack.pop();
        }

        int top() {
            return mainStack.top();
        }

        int size() {
            return mainStack.size();
        }

        bool empty() {
            return mainStack.empty();
        }
        
        int getMin() {
            return minStack.top();
        }
};

int main() {

	customStack cs;

	cs.push(10);
	cs.push(0);
	cs.push(0);

	cs.pop();

	cout << "top : " << cs.top() << endl; // 0
	cout << "min : " << cs.getMin() << endl; // 0

	return 0;
}