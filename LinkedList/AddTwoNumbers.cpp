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

ListNode<int>* sumOfLinkedList(ListNode<int>* head1, ListNode<int>* head2) {
    ListNode<int>* head = NULL;
    int carry = 0;
    while (head1 != NULL && head2 != NULL)
    {
        int sum = head1->val + head2->val + carry;
        carry = sum / 10;
        sum = sum % 10;

        head1 = head1->next;
        head2 = head2->next;
        
        insertAtHead(head, sum);
    }

    while (head1 != NULL)
    {
        int sum = head1->val + carry;
        carry = sum / 10;
        sum = sum % 10;

        head1 = head1->next;
        
        insertAtHead(head, sum);
    }

    while (head2 != NULL)
    {
        int sum = head2->val + carry;
        carry = sum / 10;
        sum = sum % 10;

        head2 = head2->next;
        
        insertAtHead(head, sum);
    }
    
    if (carry == 1) {
		ListNode<int>* n = new ListNode<int>(1);
		n->next = head;
		head = n;
	}

    return head;
}

ListNode<int>* sumOfLinkedListSimplified(ListNode<int>* head1, ListNode<int>* head2) {
    ListNode<int>* head = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry)
    {
        int d1 = head1 != NULL ? head1->val : 0;
        int d2 = head2 != NULL ? head2->val : 0;

        int sum = d1 + d2 + carry;

        insertAtHead(head, sum % 10);
        carry = sum / 10;

        head1 = head1 != NULL ? head1->next : NULL;
        head2 = head2 != NULL ? head2->next : NULL;
    }
    return head;
}

int main() {

	ListNode<int>* head1 = NULL;

	insertAtHead(head1, 1);
	insertAtHead(head1, 2);
	insertAtHead(head1, 3);

	printLL(head1);

	ListNode<int>* head2 = NULL;

	insertAtHead(head2, 4);
	insertAtHead(head2, 5);
	insertAtHead(head2, 6);

	printLL(head2);

	// ListNode<int>* head = sumOfLinkedList(head1, head2);
	ListNode<int>* head = sumOfLinkedListSimplified(head1, head2);

	printLL(head);

	return 0;
}