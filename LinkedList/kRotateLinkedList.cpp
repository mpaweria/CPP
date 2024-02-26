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

Node<int>* kRotate(Node<int>* head, int k){
    int n = listLength(head);
    k = k%n;

    Node<int>* slow = head, *fast  = head;

    while (k--)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}

int main() {

    Node<int> *head = new Node<int>(50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head);
    head = kRotate(head, 2);
    printLinkedList(head);

    return 0;
}