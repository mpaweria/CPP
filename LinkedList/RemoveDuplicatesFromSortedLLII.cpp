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

ListNode<int>* removeDuplicates(ListNode<int>* head) {
    if (head == NULL || head->next == NULL)
        return head;

    if (head->val == head->next->val) {
        while (head->next != NULL and head->val == head->next->val)
        {
            head = head->next;
        }
        return removeDuplicates(head->next);
    }
    head->next = removeDuplicates(head->next);
    return head;
}

int main() {

	ListNode<int>* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLL(head);

	head = removeDuplicates(head);

	printLL(head);

	return 0;
}