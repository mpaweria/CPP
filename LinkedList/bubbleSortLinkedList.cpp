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

int listLength(Node<int>* head){
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
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

Node<int>* bubbleSort(Node<int>* head) {
    int n = listLength(head), i=1, j=0;

    while (i <= n-1)
    {
        int j = 0;
        Node<int>* prev = NULL, *curr = head;

        while (j < n-i)
        {
            Node<int>* temp = curr->next;
            if(curr->data > temp->data) {
                curr->next = temp->next;
                temp->next = curr;

                if(prev == NULL)
                    head = temp;
                else
                    prev->next = temp;
                prev = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
            j++;
        }
        i++;
    }  
    return head;
}

int main() {

    Node<int> *head = new Node<int>(10);
    insertAtHead(head, 40);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 50);

    printLinkedList(head);

    head = bubbleSort(head);

    printLinkedList(head);

    return 0;
}