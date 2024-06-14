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

ListNode<int>* computeMidPoint(ListNode<int>* head) {
    if(head == NULL)
        return head;

    ListNode<int>* fast = head->next, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

ListNode<int>* mergeSort(ListNode<int>* head) {
    if(head == NULL || head->next == NULL)
        return head;

    ListNode<int>* midPoint = computeMidPoint(head);
    ListNode<int>* head2 = midPoint->next;
    midPoint->next = NULL;

    head = mergeSort(head);
    head2 = mergeSort(head2);
    return mergeSortedLinkedList(head, head2);
}

int main() {

	ListNode<int>* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLL(head);

	head = mergeSort(head);

	printLL(head);

	return 0;
}