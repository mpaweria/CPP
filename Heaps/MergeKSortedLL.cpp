#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class ListNode {

public :

    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(ListNode*& head, int val) {

    ListNode* n = new ListNode(val);
    n->next = head;
    head = n;

}

void printLinkedList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;

}

class ListNodeComparator {
    public:

        bool operator()(ListNode* a, ListNode* b) {
            if(a->val < b->val)
                return false;
            return true;
        }
};

ListNode* mergeKSortedLinkedList(vector<ListNode*> v) {
    priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator>  minHeap(v.begin(), v.end());

    ListNode* head = new ListNode(0);
    ListNode* dummy = head;

    while (!minHeap.empty())
    {
        ListNode* first = minHeap.top();
        minHeap.pop();
        dummy->next = first;
        dummy = dummy->next;
        if(first->next != NULL)
            minHeap.push(first->next);
    }
    return head->next;
}

int main() {

    ListNode* head1 = NULL;

    insertAtHead(head1, 7);
    insertAtHead(head1, 4);
    insertAtHead(head1, 1);

    printLinkedList(head1);

    ListNode* head2 = NULL;

    insertAtHead(head2, 8);
    insertAtHead(head2, 5);
    insertAtHead(head2, 2);

    printLinkedList(head2);

    ListNode* head3 = NULL;

    insertAtHead(head3, 9);
    insertAtHead(head3, 6);
    insertAtHead(head3, 3);

    printLinkedList(head3);

    vector<ListNode*> v = {head1, head2, head3};

    ListNode* head = mergeKSortedLinkedList(v);

    printLinkedList(head);

    return 0;
}