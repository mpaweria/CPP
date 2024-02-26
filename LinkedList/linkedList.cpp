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

int listLength(Node<int>* head){
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node<int>* insertAtHead(Node<int>* &head, int val){
    Node<int>* temp = new Node<int>(val);
    temp->next = head;
    head = temp;

    return head;
}

Node<int>* insertAtBack(Node<int>* &head, int val){
    Node<int>* temp = new Node<int>(val);
    Node<int>* itr = head;
    while(itr->next != NULL){
        itr = itr->next;
    }
    itr->next = temp;

    return head;
}

Node<int>* insertAtPos(Node<int>* &head, int val, int pos){
    if(pos < 1 || pos > listLength(head)+1)
        return head;
    else if(pos == 1)
        return insertAtHead(head, val);
    else if(pos == listLength(head))
        return insertAtBack(head, val);

    Node<int>* temp = new Node<int>(val);
    Node<int>* itr = head;

    int count = 1;
    while(count < pos-1)
    {
        itr = itr->next;
        count++; 
    }
    temp->next = itr->next;
    itr->next = temp;

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

Node<int>* deleteFromHead(Node<int>* &head){
    if(head == NULL || head->next == NULL)
        return NULL;

    Node<int> *temp = head; 
    head = head->next;
    delete temp;
    return head;
}

Node<int>* deleteFromTail(Node<int>* &head){
    Node<int>* itr = head;
    while(itr->next->next != NULL)
    {
        itr = itr->next;
    }
    Node<int>* temp = itr->next;
    itr->next = NULL;
    delete temp;
    return head;
}

Node<int>* deleteFromGivenPos(Node<int>* &head, int pos){
    if(pos < 1 || pos > listLength(head))
        return head;
    else if(pos == 1)
        return deleteFromHead(head);
    else if(pos == listLength(head))
        return deleteFromTail(head);

    Node<int>* itr = head;
    int count = 1;
    while (count < pos-1)
    {
        count++;
        itr = itr->next;
    }
    Node<int>* temp = itr->next;
    itr->next = itr->next->next;
    delete temp;

    return head;
}

bool isTargetPresent(Node<int>* head, int target){
    while (head != NULL)
    {
        if(head->data == target)
            return true;
        head = head->next;
    }
    return false;    
}

int listLengthRecursive(Node<int>* head) {
    // base case
    if(head == NULL)
        return 0;

    // recursive case
    int length = listLengthRecursive(head->next);
    return length + 1;
}

int targetPresentAtIndex(Node<int>* head, int target){
    // base case 
    if(head == NULL)
        return -1;

    // recursive case
    if(head->data == target)
        return 1;

    int index = targetPresentAtIndex(head->next, target);
    if(index != -1)
        return index + 1;

    return -1;
}

int main()
{
    Node<int> *head = new Node<int>(40);
    insertAtHead(head, 30);
    insertAtBack(head, 60);
    insertAtBack(head, 70);  
    insertAtPos(head, 10, 1);
    insertAtPos(head, 20, 2);    
    insertAtPos(head, 50, 5);   
    insertAtPos(head, 80, 8);

    printLinkedList(head);

    cout << "Is 80 present in the List: " << isTargetPresent(head, 80) << endl;
    cout << "At what index 50 is present in the List: " << targetPresentAtIndex(head, 50) << endl;

    cout << "Length of the Linked List is " << listLength(head) << endl;
    cout << "Length of the Linked List is " << listLengthRecursive(head) << endl;

    deleteFromHead(head);
    deleteFromTail(head);
    deleteFromGivenPos(head, 1);
    deleteFromGivenPos(head, 5);
    deleteFromGivenPos(head, 3);

    printLinkedList(head);

    cout << "Is 80 present in the List: " << isTargetPresent(head, 80) << endl;
    cout << "At what index 80 is present in the List: " << targetPresentAtIndex(head, 80) << endl;

    cout << "Length of the Linked List is " << listLength(head) << endl;
    cout << "Length of the Linked List is " << listLengthRecursive(head) << endl;


    return 0;
}