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

Node<int>* reverseLinkedListRecursive(Node<int>* head) {
    // base case
    if(head == NULL || head->next == NULL)
        return head;

    // recursive case
    Node<int>* recursiveHead = reverseLinkedListRecursive(head->next);

    // the next pointer of the head should point head now and head sould point NULL
    head->next->next = head;
    head->next = NULL;

    return recursiveHead;
}

int main() {

    Node<int> *head = new Node<int>(50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head);
    head = reverseLinkedListIterative(head);
    printLinkedList(head);
    head = reverseLinkedListIterative(head);
    printLinkedList(head);

    return 0;
}