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

ListNode<int>* mergeSortedLinkedList(ListNode<int>* head1, ListNode<int>* head2) {
    ListNode<int>* head = new ListNode<int>(0);
    ListNode<int>* temp = head;

    while (head1 != NULL && head2 != NULL)
    {
        if(head1->val < head2->val) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if (head1 != NULL)
    {
        temp->next = head1;
    }
    if(head2 != NULL)
    {
        temp->next = head2;
    }
    return head->next;
}

ListNode<int>* mergeSortedLinkedListRecursive(ListNode<int>* head1, ListNode<int>* head2) {
    // base case
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;

    // recursive case
    if(head1->val < head2->val) {
        ListNode<int>* head = head1;
        head->next = mergeSortedLinkedListRecursive(head1->next, head2);
        return head;
    } else {
        ListNode<int>* head = head2;
        head->next = mergeSortedLinkedListRecursive(head1, head2->next);
        return head;
    }
}

int main() {

	ListNode<int>* head1 = NULL;

	insertAtHead(head1, 50);
	insertAtHead(head1, 30);
	insertAtHead(head1, 10);

	printLL(head1);

	ListNode<int>* head2 = NULL;

	insertAtHead(head2, 70);
    insertAtHead(head2, 60);
	insertAtHead(head2, 40);
	insertAtHead(head2, 20);

	printLL(head2);

	// ListNode<int>* head = mergeSortedLinkedList(head1, head2);
	ListNode<int>* head = mergeSortedLinkedListRecursive(head1, head2);

	printLL(head);

	return 0;
}