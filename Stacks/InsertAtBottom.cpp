#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s) {

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

// Time Complexity - O(n) -> 4n + 1 steps
// Space Complexity - O(n)
void insertAtBottomIterative(stack<int> &s, int val) {
    stack<int> temp;

    // takes 2n steps
    while (!s.empty())
    {
        int num = s.top();
        temp.push(num);
        s.pop();
    }
    s.push(val);

    // takes 2n steps
    while (!temp.empty())
    {
        int num = temp.top();
        s.push(num);
        temp.pop();
    }
}

// Time Complexity - O(n) -> 4n + 1 steps
// Space Complexity - O(n) -> function call stack
void insertAtBottom(stack<int> &s, int data) {
    // base case
    if(s.empty()) {
        s.push(data);
        return;
    }

    // recursive case
    int val = s.top();
    s.pop();

    insertAtBottom(s, data);

    s.push(val);
}

int main() {
    stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	int data = 0;

	insertAtBottom(s, data);

	print(s);

    return 0;
}