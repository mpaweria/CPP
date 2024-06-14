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

template <typename T>
void insertAtLast(ListNode<T>* &head, T val) {
    ListNode<T>* node = new ListNode<T>(val);

    if(head == NULL)
        head = node;

    ListNode<T>* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

template <typename T>
void insertAtPosition(ListNode<T>* &head, T val, T pos) {
    ListNode<T>* node = new ListNode<T>(val);

    if(pos == 0)
        insertAtHead(head, val);

    if(pos == LLlength(head)) {
        insertAtLast(head, val);
    }

    ListNode<T>* temp = head;

    int count = 0;

    while (count < pos-1)
    {
        temp = temp->next;
        count++;
    }
    node->next = temp->next;
    temp->next = node;
}

template <typename T>
void deleteFromHead(ListNode<T>* &head) {
    if(head != NULL) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void deleteFromLast(ListNode<T>* &head) {
    ListNode<T>* temp = head;
    ListNode<T>*prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}

template <typename T>
void deleteFromPosition(ListNode<T>* &head, T pos) {
    if(pos == 0)
        deleteFromHead(head);

    if(pos == LLlength(head)) {
        deleteFromLast(head);
    }

    ListNode<T>* temp = head, *node = NULL;

    int count = 0;

    while (count < pos-1)
    {
        temp = temp->next;
        count++;
    }
    node = temp->next;
    temp->next = node->next;
    delete node;
}

template <typename T>
bool find(ListNode<T>* head, T target) {
    if(head == NULL)
        return false;

    while (head->next != NULL)
    {
        if(head->val == target)
            return true;
        head = head->next;
    }
    return false;
}

template <typename T>
void reverse(ListNode<T>* &head) {

    ListNode<T>* temp = head, *prev = NULL;

    while (temp != NULL)
    {
        ListNode<T>* curr = temp;
        temp = temp->next;
        curr->next = prev;
        prev = curr;
    }
    head = prev;
}

int main() {
    ListNode<int>* head = new ListNode<int>(30);

    insertAtHead(head, 20);
    insertAtHead(head, 10);

    insertAtLast(head, 50);

    insertAtPosition(head, 40, 3);

    cout << "Length of LL: " << LLlength(head) << endl;

    printLL(head);

    reverse(head);
    
    printLL(head);

    cout << find(head, 40) << endl;

    deleteFromHead(head);

    deleteFromLast(head);

    deleteFromPosition(head, 1);

    printLL(head);

    cout << find(head, 30) << endl;

    return 0;
}