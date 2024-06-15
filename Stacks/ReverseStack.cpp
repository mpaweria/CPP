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

// Time Complexity: O(n)
// Space Complexity: O(n)
stack<int> reverseIterative(stack<int> s) {
    stack<int> s2; 

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        s2.push(val);
    }
    return s2;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
void reverse(stack<int> &s) {
    // base case
    if(s.size() == 1 || s.empty())
        return;

    // recursive case
    int val = s.top();
    s.pop();

    reverse(s);

    insertAtBottom(s, val);
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

	reverse(s);

	print(s);

    s = reverseIterative(s);

	print(s);

    return 0;
}