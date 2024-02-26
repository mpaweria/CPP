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

int listLength(Node<int>* head){
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node<int>* kReverse(Node<int>* head, int k) {
    int length = listLength(head);
    // base case
    if(head == NULL || length < k)
        return head;

    // recursive case
    int i=1;
    Node<int> *prev = NULL, *curr = head;

    while (curr != NULL && i <= k)
    {
        Node<int>* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        i++;
    }

    Node<int>* recursiveHead = kReverse(curr, k);
    head->next = recursiveHead;

    return prev;
} 

int main() {

    Node<int> *head = new Node<int>(80);
    insertAtHead(head, 70);
    insertAtHead(head, 60);
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head);
    head = kReverse(head, 3);
    printLinkedList(head);

    return 0;
}