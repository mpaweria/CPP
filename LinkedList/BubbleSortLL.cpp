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

ListNode<int>* bubbleSort(ListNode<int>* head) {
    if(head == NULL)
        return head;

    int n = LLlength(head), i=1;

    while (i < n)
    {
        int j = 0;
        ListNode<int>* curr = head, *prev = NULL;
        while (j < n-i)
        {
            ListNode<int>* temp = curr->next;
            if(curr->val > temp->val) {
                curr->next = temp->next;
                temp->next = curr;

                prev == NULL ? head = temp : prev->next = temp;
                prev = temp;;
            } else {
                prev = curr;
                curr = curr->next;
            }
            j++;
        }
        i++;
    }
    return head;
}

int main() {

	ListNode<int>* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLL(head);

	head = bubbleSort(head);

	printLL(head);

	return 0;
}