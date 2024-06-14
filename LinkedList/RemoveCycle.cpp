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

void removeCycle(ListNode<int>* &head) {
    if(head == NULL)
        return;

    ListNode<int>* fast = head, *slow = head;

    while (true)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            break;
    }
    slow = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main() {

	ListNode<int>* head = new ListNode<int>(10);
	head->next = new ListNode<int>(20);
	head->next->next = new ListNode<int>(30);
	head->next->next->next = new ListNode<int>(40);
	head->next->next->next->next = new ListNode<int>(50);
	head->next->next->next->next->next = new ListNode<int>(60);
	head->next->next->next->next->next->next = head->next->next;

	removeCycle(head);

    head->next->next->next->next->next->next == NULL ? cout << "Cycle removed!!" : cout << "Error!"; 

	return 0;
}