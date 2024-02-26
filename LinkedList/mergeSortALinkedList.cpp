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

Node<int>* merge(Node<int>* head1, Node<int>* head2) {

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


Node<int>* mergeSort(Node<int>* head) {

    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    // recursive case
    Node<int>* midPoint = midPointOfLinkedList(head);
    Node<int>* head2 = midPoint->next;
    midPoint->next = NULL;
    head = mergeSort(head);
    head2 = mergeSort(head2);

    return merge(head, head2);
}

int main() {

    Node<int> *head = new Node<int>(10);
    insertAtHead(head, 40);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 50);

    printLinkedList(head);

    head = mergeSort(head);

    printLinkedList(head);

    return 0;
}