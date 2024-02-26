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

Node<int>* sum(Node<int>* head1, Node<int>* head2) {
    Node<int>* head = NULL;
    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        int sum = head1->data + head2->data + carry;
        insertAtHead(head, sum%10);
        carry = sum/10;
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1 != NULL)
    {
        int sum = head1->data + carry;
        insertAtHead(head, sum%10);
        carry = sum/10;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        int sum = head2->data + carry;
        insertAtHead(head, sum%10);
        carry = sum/10;
        head2 = head2->next;
    }
    if(carry){
        insertAtHead(head, carry);
    }

    return head; 
}

Node<int>* sumSimplified(Node<int>* head1, Node<int>* head2) {
    Node<int>* head = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry)
    {
        int d1 = head1 != NULL ? head1->data : 0;
        int d2 = head2 != NULL ? head2->data : 0;
        int sum = d1 + d2 + carry;
        insertAtHead(head, sum%10);
        carry = sum/10;
        head1 = head1 != NULL ? head1->next : NULL;
        head2 = head2 != NULL ? head2->next : NULL;
    }
    return head;
}

int main() {

    Node<int> *head1 = new Node<int>(1);
    insertAtHead(head1, 2);
    insertAtHead(head1, 3);

    Node<int> *head2 = new Node<int>(9);
    insertAtHead(head2, 9);
    insertAtHead(head2, 9);
    insertAtHead(head2, 9);
    insertAtHead(head2, 9);

    cout << "Linked list 1: ";
    printLinkedList(head1);

    cout << "Linked list 2: ";
    printLinkedList(head2);

    // Node<int>* head = sum(head1, head2);
    Node<int>* head = sumSimplified(head1, head2);
    cout << "Sum linked list: ";
    printLinkedList(head);

    return 0;
}