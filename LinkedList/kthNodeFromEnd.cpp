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

Node<int>* kthNodeFromEnd(Node<int>* head, int k) {
    if(head == NULL)
        return head;
        
    int count = 1;
    Node<int>* fast = head, *slow = head;

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

    Node<int> *head = new Node<int>(60);
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    int k = 2;
    Node<int>* kNodeFromEnd = kthNodeFromEnd(head, k);

    if (kNodeFromEnd != NULL)
        cout << "The " << k << " node from end is: " << kNodeFromEnd->data;
    else
        cout << "List is empty!";     

    return 0;
}