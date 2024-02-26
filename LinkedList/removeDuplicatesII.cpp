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

Node<int>* removeDuplicatesIterative(Node<int>* head) {

    Node<int>* dummy = new Node<int>(0);
    Node<int>* prev = dummy;

    while (head != NULL)
    {
        if(head->next != NULL && head->data == head->next->data) {
            while (head->next != NULL && head->data == head->next->data)
            {
                head = head->next;
            }
            prev->next = head->next;
        } else {
            prev = prev->next;
        }
        head = head->next;
    }
    return dummy->next;
}

Node<int>* removeDuplicatesRecursive(Node<int>* head) {
    // base case
    if(head == NULL || head->next == NULL)
        return head;

    // recursive case
    if(head->data != head->next->data)
    {
        head->next = removeDuplicatesRecursive(head->next);
        return head;
    }
    else 
    {
        while (head->next != NULL && head->data == head->next->data)
        {
            head = head->next;
        }
        return removeDuplicatesRecursive(head->next);
    }
}

int main() {

    Node<int> *head = new Node<int>(40);
    insertAtHead(head, 30);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    insertAtHead(head, 10);

    printLinkedList(head);
    // head = removeDuplicatesRecursive(head);
    head = removeDuplicatesIterative(head);
    printLinkedList(head);

    return 0;
}