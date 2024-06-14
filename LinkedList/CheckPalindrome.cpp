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

ListNode<int>* computeMidPoint(ListNode<int>* head) {
    if(head == NULL)
        return head;

    ListNode<int>* fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
ListNode<int>* reverse(ListNode<T>* head) {

    ListNode<T>* temp = head, *prev = NULL;

    while (temp != NULL)
    {
        ListNode<T>* curr = temp;
        temp = temp->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}

bool isPalindrome(ListNode<int>* head) {
    if(!head)
        return true;

    ListNode<int>* midPoint = computeMidPoint(head);
    ListNode<int>* head2 = reverse(midPoint);

    while (head != NULL && head2 != NULL)
    {
        if(head->val != head2->val)
            return false;

        head = head->next;
        head2 = head2->next;
    }
    return true;
}

int main() {
    ListNode<int>* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLL(head);

	isPalindrome(head) ? cout << "palindrome" << endl : cout << "not a palindrome" << endl;

	return 0;
}