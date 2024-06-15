#include<iostream>
using namespace std;

template <typename T>
class ListNode {
    public:
    T val;
    ListNode* next;

    ListNode(T val) {
        this->val = val;
        this->next = NULL;
    }
};

template <typename T>
class ForewardList {
    ListNode<T>* head;
    int count;

    public:
        ForewardList() {
            head = NULL;
            count = 0;
        }

        void push_front(T val) {
            ListNode<T>* n = new ListNode<T>(val);
            n->next = head;
            head = n;
            count++;
        }
        
        void pop_front() {
            if(!head) {
                cout << "Stack Underflow!";
                return;
            }
            ListNode<T>* n = head;
            head = head->next;
            delete n;
            count--;
        }

        int size() {
            return count;
        }

        T front() {
            return head->val;
        }

        bool empty() {
            return head == NULL;
        }
};

template <typename T>
class Stack {
    ForewardList<T> ll;

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
            return ll.size();
        }

        bool empty() {
            return ll.empty();
        }
};

int main() {
    
    Stack<int> s;

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