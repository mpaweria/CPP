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
void printLL(ListNode<T>* head) {
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

template <typename T>
void insertAtHead(ListNode<T>* &head, T val) {
    ListNode<T>* node = new ListNode<T>(val);
    node->next = head;
    head = node;
}

ListNode<int>* rotateLinkedList(ListNode<int>* head, int k) {
    ListNode<int>* temp = head;
    int n = LLlength(head);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;

    k = k % n;
    while (k--)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;

    return head;
}

int main() {

	ListNode<int>* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLL(head);

	int k = 2;

	head = rotateLinkedList(head, k);

	printLL(head);

	return 0;
}