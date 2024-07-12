#include<iostream>
using namespace std;

class node {
    public:

        int key;
        int val;
        node* next;

        node(int k, int v){
            this->key = k;
            this->val = v;
            this->next = NULL;
        }
};

class HashMap {
    int n;
    int m;
    double loadFactor;

    node** t;

    int hashFunction(int k) {
        return k%n;
    }

    void transfer(node* head) {
        node* temp = head;
        while (temp != NULL)
        {
            insert(temp->key, temp->val);
            temp = temp->next;
        }
        
        while (head != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void rehash() {
        node** oldt = t;
        int oldN = n;
        m = 0;

        n = 2*n;
        t = new node*[n];
        for(int i=0; i<n; i++)
            t[i] = NULL;

        for(int i=0; i<oldN; i++) 
            transfer(oldt[i]);

        delete [] oldt;
    }

    public: 
        HashMap(int n = 5, double l = 0.7) {
            this->n = n;
            this->m = 0;
            this->loadFactor = l;

            t = new node*[n];
            for(int i=0; i<n; i++)
                t[i] = NULL;
        }

        void insert(int key, int val) {
            int hashIdx = hashFunction(key);

            node* temp = new node(key, val);
            temp->next = t[hashIdx];
            t[hashIdx] = temp;
            m++;

            double lf = m * (1.0) / n;
            
            if(lf > loadFactor) {
                cout << "Rehashing due to loadfactor: " << lf << endl;
                rehash();
            }
        }

        node* find(int key) {
            int hashIdx = hashFunction(key);

            node* temp = t[hashIdx];

            while (temp != NULL)
            {
                if(temp->key == key)
                    break;
                temp = temp->next;
            }
            return temp;
        }

        void erase(int key) {
            int hashIdx = hashFunction(key);

            node* temp = t[hashIdx];

            if(temp == NULL)
                return;

            if(temp->key == key) {
                t[hashIdx] = temp->next;
                delete temp;

                m--;
                return;
            }

            node* prev = NULL;

            while(temp != NULL) {
                if(temp->key = key) {
                    prev->next = temp->next;
                    delete temp;

                    m--;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        void printLinkedList(node* head) {
            while (head) { // head != NULL
                cout << "(" << head->key << ", " << head->val << ") ";
                head = head->next;
            }
            cout << endl;
        }

        void printHashMap() {
            // iterate over buckets in the hashMap
            for (int i = 0; i < n; i++) {
                // print the linkedList stored ith bucket of the hashMap
                cout << i << " : ";
                printLinkedList(t[i]);
            }
            cout << endl;
        }
};

int main() {
    HashMap hashMap;

    hashMap.insert(0, 0);
    hashMap.insert(1, 1);
    hashMap.insert(6, 36);

    hashMap.printHashMap();

    int key = 0;

    node* temp = hashMap.find(key);

    temp ? cout << key << " found, value: " << temp->val : cout << key << " not found";
    cout << endl;

    hashMap.erase(key);
    
    temp = hashMap.find(key);

    temp ? cout << key << " found, value: " << temp->val : cout << key << " not found";
    cout << endl;

    hashMap.printHashMap();

    hashMap.insert(11, 121);
    hashMap.insert(10, 100);

    hashMap.printHashMap();

    return 0;
}