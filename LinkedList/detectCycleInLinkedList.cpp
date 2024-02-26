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

bool detectCycle(Node<int>* head){
    Node<int> *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }
    return false;    
}

int main() {

    Node<int> *head = new Node<int>(60);
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    head->next->next->next->next = head;
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    cout << "Is cycle present: " << detectCycle(head);

    return 0;
}