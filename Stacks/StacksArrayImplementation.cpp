#include<iostream>
using namespace std;

template <typename T>
class Stack {

    T* arr;
    int t;
    int n;

    public:
        
        Stack(int n) {
            arr = new T[n];
            t = -1;
            this->n = n;
        }

        void push(T val) {
            if(t == n-1) {
                cout << "Stack Overflow!";
                return;
            }
            t++;
            arr[t] = val;
        }

        void pop() {
            if(t == -1) {
                cout << "Stack Underflow!";
                return;
            }
            t--;
        }

        T top() {
            if(t == -1) {
                cout << "Stack is empty!";
                return -1;
            }
            return arr[t];
        }

        bool empty() {
            return t == -1;
        }

        int size() {
            return t+1;
        }
};

int main() {

	Stack<char> s(5);

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');
	s.push('E');

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

    Stack<int> st(5);

    st.push(1);
    st.push(2); 

    cout << st.top() << endl;

    st.size();

    st.pop();
    cout << st.top() << endl;
    st.pop();

    st.empty() ? cout << "Stack is empty!" : cout << "Stack is not empty!";

    return 0;
}