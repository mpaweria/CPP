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

template <typename T>
ListNode<T>* kReverse(ListNode<T>* head, int k) {
    // base case
    int length = LLlength(head);
    if(head == NULL || length < k)
        return head;

    ListNode<T>* temp = head, *prev = NULL;
    int i = 0;

    while (temp != NULL && i < k)
    {
        ListNode<T>* curr = temp;
        temp = temp->next;
        curr->next = prev;
        prev = curr;
        i++;
    }
    head->next = kReverse(temp, k);
    return prev;
}

int main() {

	ListNode<int>* head = NULL;

	insertAtHead(head, 80);
	insertAtHead(head, 70);
	insertAtHead(head, 60);
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLL(head);

	int k = 3;

	head = kReverse(head, k);

	printLL(head);

	return 0;
}