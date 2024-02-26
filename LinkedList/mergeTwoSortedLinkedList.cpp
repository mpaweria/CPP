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

Node<int>* mergeLinkedListIterative(Node<int>* head1, Node<int>* head2) {

    Node<int>* dummy = new Node<int>(0);
    Node<int>* temp = dummy;

    while (head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data) {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        } else {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }
    if(head1 == NULL) {
        temp->next = head2;
    } else {
        temp->next = head1;
    }

    return dummy->next;
}

Node<int>* mergeLinkedListRecursive(Node<int>* head1, Node<int>* head2) {
    // base case
    if (head1 == NULL && head2 == NULL)
        return NULL;
    else if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    // recursive case 

    if(head1->data < head2->data) {
        Node<int>* head = head1;
        Node<int>* temp = mergeLinkedListRecursive(head1->next, head2);
        head->next = temp;
        return head;
    } else {
        Node<int>* head = head2;
        Node<int>* temp = mergeLinkedListRecursive(head1, head2->next);
        head->next = temp;
        return head;
    }
}

int main() {

    Node<int> *head1 = new Node<int>(70);
    insertAtHead(head1, 30);
    insertAtHead(head1, 10);

    printLinkedList(head1);

    Node<int> *head2 = new Node<int>(60);
    insertAtHead(head2, 50);
    insertAtHead(head2, 20);

    printLinkedList(head2);

    head1 = mergeLinkedListRecursive(head1, head2);

    printLinkedList(head1);

    return 0;
}