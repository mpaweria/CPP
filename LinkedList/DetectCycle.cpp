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
void printLL(ListNode<T>* head) {
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

template <typename T>
int LLlength(ListNode<T>* head) {
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}


template <typename T>
void insertAtHead(ListNode<T>* &head, T val) {
    ListNode<T>* node = new ListNode<T>(val);
    node->next = head;
    head = node;
}

bool isCyclePresent(ListNode<int>* head) {
    if(head == NULL)
        return false;

    ListNode<int>* fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}

int main() {

	ListNode<int>* head = new ListNode<int>(10);
	head->next = new ListNode<int>(20);
	head->next->next = new ListNode<int>(30);
	head->next->next->next = new ListNode<int>(40);
	head->next->next->next->next = new ListNode<int>(50);
	head->next->next->next->next->next = new ListNode<int>(60);
	head->next->next->next->next->next->next = head->next->next;
    
    // ListNode<int>* head = new ListNode<int>(60);

	// insertAtHead(head, 50);
	// insertAtHead(head, 40);
	// insertAtHead(head, 30);
	// insertAtHead(head, 20);
	// insertAtHead(head, 10);

	isCyclePresent(head) ? cout << "cycle found" << endl : cout << "cycle not found" << endl;

	return 0;
}