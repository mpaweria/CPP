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

ListNode<int>* findkthLastNode(ListNode<int>* head, int k) {
    if(head == NULL)
        return head;

    ListNode<int>* fast = head, *slow = head;
    while (k--)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }    

    return slow;
}

int main() {

	ListNode<int>* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLL(head);

	int k = 3; // assume k <= n

	ListNode<int>* kthLastNode = findkthLastNode(head, k);
	cout << kthLastNode->val << endl;

	return 0;
}