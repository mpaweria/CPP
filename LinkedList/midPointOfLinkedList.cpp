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

// Taking fast as head->next makes a difference when we've even length list:
// If we take fast = head, then it returns the n/2+1 node as mid point
// And if fast = head->next, then it returns the n/2 node as mid point
Node<int>* midPointOfLinkedList(Node<int>* head) {
    if(head == NULL)
        return head;
        
    Node<int>* slow = head, *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
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

    Node<int> *midPoint = midPointOfLinkedList(head);
    if(midPoint != NULL) {
        cout << "Mid point of the given linked list is: " << midPoint->data;
    } else {
        cout << "LinkedList is empty!";
    }   

    return 0;
}