#include<iostream>
using namespace std;

template <typename T>
class Node
{
    public: 
        T data;
        Node *next; 

        Node(T data){
            this->data = data;
            this->next = NULL;
        }
};

Node<int>* insertAtHead(Node<int>* &head, int val){
    Node<int>* temp = new Node<int>(val);
    temp->next = head;
    head = temp;

    return head;
}

void printLinkedList(Node<int>* head){
    Node<int> *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp =  temp->next;
    }
    cout << endl;
}

Node<int>* midPointOfLinkedList(Node<int>* head) {
    Node<int>* slow = head, *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node<int>* reverseLinkedListIterative(Node<int>* head) {
    Node<int> *prev = NULL, *curr = head;

    while (curr != NULL)
    {
        Node<int>* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool checkPalindrome(Node<int>* head){
    Node<int>* mid = midPointOfLinkedList(head);
    Node<int>* head2 = mid->next;
    mid->next = NULL;

    head2 = reverseLinkedListIterative(head2);

    while (head2 != NULL)
    {
        if(head->data != head2->data)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}

int main() {

    Node<int> *head = new Node<int>(10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head);
    cout << checkPalindrome(head);

    return 0;
}