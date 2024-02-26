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

Node<int>* removeDuplicates(Node<int>* head){
    Node<int>* curr = head;
    while (curr->next != NULL)
    {
        if(curr->data == curr->next->data){
            Node<int> *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
            curr = curr->next;
    }
    return head;
}

int main() {

    Node<int> *head = new Node<int>(40);
    insertAtHead(head, 30);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    insertAtHead(head, 10);
    insertAtHead(head, 10);
    insertAtHead(head, 10);

    printLinkedList(head);
    head = removeDuplicates(head);
    printLinkedList(head);

    return 0;
}